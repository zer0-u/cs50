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


def get_user_id():
    return session["user_id"]


def fetch_cash(id):
    return int(db.execute("SELECT cash FROM users WHERE id = ?", id)[0]["cash"])


def fetch_price(symbol):
    quote = lookup(symbol)
    if not quote:
        return None
    return int(quote["price"])


def update_cash(user_id, cash):
    db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)


def insert_transactions(user_id, symbol, shares, price):
    db.execute("INSERT INTO transactions(user_id, symbol, shares, price) \
               VALUES(?, ?, ?, ?)",
               user_id, symbol, shares, price)


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_id = get_user_id()
    cash = fetch_cash(user_id)
    stocks = db.execute(
        "SELECT symbol, SUM(shares) AS shares FROM transactions \
            WHERE user_id = ? GROUP BY symbol",
        user_id)

    stock_total = 0
    for stock in stocks:
        quote = lookup(stock["symbol"])
        total = quote["price"] * int(stock["shares"])
        stock["name"] = quote["name"]
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

    user_id = get_user_id()
    symbol = request.form.get("symbol")
    shares = request.form.get("shares")

    if not symbol:
        return apology("Symbolを入力してください", 400)
    if not shares or not shares.isdigit():
        return apology("整数を入力してください", 400)

    shares = int(shares)

    cash = fetch_cash(user_id)
    price = fetch_price(symbol)
    if not price:
        return apology(f"存在しない銘柄です:{symbol}", 400)

    remain = cash - (price * shares)
    if remain < 0:
        return apology("残高が足りません", 403)

    update_cash(user_id, remain)
    insert_transactions(user_id, symbol, shares, price)

    return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT symbol, shares, price, transacted FROM transactions \
               WHERE user_id = ?", get_user_id())
    return render_template("history.html", history=history)


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
# @login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    symbol = request.form.get("symbol")
    if not symbol:
        return apology("銘柄を入力してください", 400)
    result = lookup(symbol)
    if not result:
        return apology(f"存在しない銘柄です:{symbol}", 400)
    return render_template("quoted.html", result=result)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")

    # 入力値を取得する
    name = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")
    # 入力値を検証する
    if not name:
        return apology("ユーザ名を入力してください", 400)
    if not password:
        return apology("パスワードを入力してください", 400)
    if not confirmation:
        return apology("パスワード(確認)を入力してください", 400)
    if password != confirmation:
        return apology("パスワードが一致しません", 400)
    check = db.execute("SELECT username FROM users WHERE username = ?", name)
    if check:
        return apology(f"{name}はすでに登録されています", 400)
    # パスワードはハッシュ化したものを保存する
    hash = generate_password_hash(password)
    # DBに保存する
    db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", name, hash)
    # TODO 自動的にログインできないか？
    return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = get_user_id()
    rows = db.execute(
        "SELECT DISTINCT symbol FROM transactions WHERE user_id = ?", user_id)
    symbols = []
    for row in rows:
        symbols.append(row["symbol"])

    if request.method == "GET":
        return render_template("sell.html", symbols=symbols)

    symbol = request.form.get("symbol")
    shares = request.form.get("shares")
    if not symbol or symbol not in symbols:
        return apology("銘柄を選択してください", 400)
    if not shares.isdigit() or int(shares) < 1:
        return apology("1以上の整数を入力してください", 400)

    shares = int(shares)

    current_shares = int(db.execute(
        "SELECT SUM(shares) AS shares FROM transactions WHERE user_id = ? AND symbol = ?",
        user_id, symbol)[0]["shares"])
    if shares > current_shares:
        return apology(f"1以上所持数({current_shares})以下の整数を入力してください", 400)

    current_cash = fetch_cash(user_id)
    price = fetch_price(symbol)
    updated_cash = current_cash + (price * shares)
    update_cash(user_id, updated_cash)
    insert_transactions(user_id, symbol, -shares, price)
    return redirect("/")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
