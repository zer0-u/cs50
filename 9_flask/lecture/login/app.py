from flask import Flask, redirect, render_template, request, session
# Flaskが用意したセッション機能
from flask_session import Session

app = Flask(__name__)

# セッションを設定する
# ブラウザが閉じた時にセッションも閉じる
app.config["SESSION_PERMANENT"] = False
# Cookieをサーバのハードディスクに保存する
# アプリケーションを実行するとFlask_sessionというフォルダが生成される
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    # ログインボタンを押したらPOSTリクエストが送信される
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    # 単純にログインフォームへアクセスした場合はGETリクエスト
    return render_template("login.html")


@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")
