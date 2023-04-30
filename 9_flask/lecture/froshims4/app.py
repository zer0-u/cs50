from cs50 import SQL
from flask import Flask, redirect, render_template, request


app = Flask(__name__)

# DBに接続する
# ://はURIのための文字で、3つ目の/はカレントディレクトリを表すもの
db = SQL("sqlite:///froshims.db")


SPORTS = [
    "basketball",
    "foorball",
    "ultimate frisbee"
]


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


# 登録情報を削除する
@app.route("/deregister", methods=["POST"])
def deregister():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")


@app.route("/register", methods=["POST"])
def register():
    # 入力値チェック
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html")

    # 登録
    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)

    # 結果画面へリダイレクト
    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)
