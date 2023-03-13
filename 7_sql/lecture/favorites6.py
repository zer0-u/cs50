import csv
from cs50 import SQL

# DBに接続する
db = SQL("sqlite:///favorites.db")

# タイトルを入力してもらう
title = input("title: ").strip()


