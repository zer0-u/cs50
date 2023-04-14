# 使うものをimportする
from flask import Flask, render_template, request

# __name__は現在のファイル名を差している
# Flask関数で現在のファイルをFlaskアプリケーションに変換し、変数appに代入する
app = Flask(__name__)

# 引数のないindex関数でindex.htmlのレンダリング結果を返す
# index.htmlはこれから作る(どこかにある想定)
# @から始まる文字列は「デコレータ」と呼ぶ(アノテーションではない)
# /(アプリケーションルート)
@app.route("/")
def index():
    return render_template("index.html")