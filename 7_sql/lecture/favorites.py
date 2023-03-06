import csv

with open("sample.csv", "r")as file:
    reader = csv.reader(file)
    next(reader)  # ひとまずヘッダは飛ばす
    for row in reader:
        print(row[1])  # タイトルだけ出力する
