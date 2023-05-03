import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


def fetch_cash(id):
    return int(db.execute("SELECT cash FROM users WHERE id = ?", id)[0]["cash"])


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_id = session["user_id"]
    cash = fetch_cash(user_id)
    stocks = db.execute(
        "SELECT symbol, SUM(shares) AS shares FROM transactions WHERE user_id = ? GROUP BY symbol",
        user_id)

    stock_total = 0
    for stock in stocks:
        quote = lookup(stock["symbol"])
        total = quote["price"] * int(stock["shares"])
        stock["price"] = quote["price"]
        stock["total"] = total
        stock_total += total

    portfolio = {
        "stocks": stocks,
        "cash": cash,
        "total": stock_total + cash
    }
    return render_template("index.html", portfolio=portfolio)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if (request.method == "GET"):
        return render_template("buy.html")

    user_id = session["user_id"]
    symbol = request.form.get("symbol")
    shares = request.form.get("shares")

    if not symbol:
        return apology("Symbolを入力してください")
    if not shares or not shares.isdigit():
        return apology("整数を入力してください")

    shares = int(shares)

    cash = fetch_cash(user_id)

    require = lookup(symbol)["price"] * shares

    remain = cash - require
    if remain < 0:
        return apology("残高が足りません")

    db.execute("UPDATE users SET cash = ? WHERE id = ?", remain, user_id)
    db.execute(
        "INSERT INTO transactions(user_id, symbol, shares) VALUES(?, ?, ?)",
        user_id, symbol, shares)

    return apology("DONE!")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    symbol = request.form.get("symbol")
    if not symbol:
        return apology("must input symbol", 403)
    result = lookup(symbol)
    return render_template("quoted.html", result=result)


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")

    """Register user"""
    # 入力値を取得する
    name = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")
    # 入力値を検証する
    if not name:
        return apology("must input username", 403)
    if not password:
        return apology("must input password", 403)
    if not confirmation:
        return apology("must input confirmation", 403)
    if password != confirmation:
        return apology("input same password", 403)
    # パスワードはハッシュ化したものを保存する
    hash = generate_password_hash(password)
    # DBに保存する
    db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", name, hash)
    # TODO 自動的にログインできないか？
    return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
# @login_required
def sell():
    """Sell shares of stock"""
    # user_id = session["user_id"]
    user_id=1
    if request.method == "GET":
        rows = db.execute(
            "SELECT DISTINCT symbol AS symbol FROM transactions WHERE user_id = ?", user_id)
        symbols = []
        for row in rows:
            symbols.append(row["symbol"])
        return render_template("sell.html", symbols=symbols)
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
