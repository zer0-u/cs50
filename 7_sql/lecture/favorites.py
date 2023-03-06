import csv

titles = set()

with open("sample.csv", "r")as file:
    # reader = csv.reader(file)
    # next(reader)  # ひとまずヘッダは飛ばす
    # for row in reader:
    #     print(row[1])  # タイトルだけ出力する
    reader = csv.DictReader(file)  # DictReaderを使うと堅牢性が増す
    for row in reader:
        titles.add(row["title"].strip().upper())  # 正規化も行う

for title in sorted(titles):
    print(title)
