from flask import Flask, redirect, render_template, request


app = Flask(__name__)

# nameとsportの関連を保持する辞書(現在は空)
REGISTRANTS = {}

SPORTS = [
    "basketball",
    "foorball",
    "ultimate frisbee"
]


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    # 入力値チェック
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="missing name")

    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="invalid sport")

    # 登録
    REGISTRANTS[name] = sport

    # 結果画面へリダイレクト
    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
