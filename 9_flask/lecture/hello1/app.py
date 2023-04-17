# 使うものをimportする
from flask import Flask, render_template, request

# __name__は現在のファイル名を差している
# Flask関数で現在のファイルをFlaskアプリケーションに変換し、変数appに代入する
app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/greet")
def greet():
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)
