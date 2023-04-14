# 使うものをimportする
from flask import Flask, render_template, request

# __name__は現在のファイル名を差している
# Flask関数で現在のファイルをFlaskアプリケーションに変換し、変数appに代入する
app = Flask(__name__)

# 引数のないindex関数でindex.htmlのレンダ・テンプレートを返す
# index.htmlはこれから作る(どこかにある想定)
# @から始まる文字列は「デコレータ」と呼ぶ(アノテーションではない)
# /(アプリケーションルート)にアクセスしたときの挙動を定義
@app.route("/")
def index():
    # クエリパラメータ内にある「name」というキーに紐づいた値を変数nameに代入する
    name = request.args.get("name")
    # render_template関数は複数の引数を取れる
    # 2つ目以降は好きな変数を指定できる
    # 変数nameを、テンプレート内で「name」として参照できるように指定した
    return render_template("index.html", name=name)
