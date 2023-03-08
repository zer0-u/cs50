import csv

with open("favorites.csv", "r") as file:
    # reader = csv.reader(file)
    # next(reader)
    # for row in reader:
    #     print(row[1])  # タイトルを一覧表示
    reader = csv.DictReader(file)
    for row in reader:
        print(row["title"])
