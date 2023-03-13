import csv
from cs50 import SQL

# DBに接続する
db = SQL("sqlite:///favorites.db")

# タイトルを入力してもらう
title = input("title: ").strip()

# SELECT文を実行する
# ?はプレースホルダ
# 戻り値は行のリスト
rows = db.execute("SELECT COUNT(*) FROM favorites WHERE title LIKE ?", title)

# 結果を取り出す
# 今回はCOUNT(*)だから1行目(0番目)にあると分かりきっている
row = rows[0]
