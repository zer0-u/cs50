import os
import re


from flask import Flask, render_template, request

# requirements.txtにFlask Mailを追加する必要がある？
from flask_mail import Mail, Message


app = Flask(__name__)


# 設定変数を追加する
# app.configはappが生成された時に追加されるdict
# os.environは環境変数(機密情報のハードコードは避ける)
app.config["MAIL_DEFAULT_SENDER"] = os.environ["MAIL_DEFAULT_SENDER"]
app.config["MAIL_PASSWORD"] = os.environ["MAIL_PASSWORD"]
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.environ["MAIL_USERNAME"]
mail = Mail(app)


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
    email = request.form.get("email")
    sport = request.form.get("sport")
    if not name or not email or sport not in SPORTS:
        return render_template("failure.html")

    # メールを送信する
    # Messageの第一引数は件名
    # recipientsはメールを受け取るべきアドレスのリスト
    message = Message("You are registered!", recipients=[email])
    mail.send(message)

    return render_template("success.html")
