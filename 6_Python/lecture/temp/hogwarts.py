import csv

houses = {
    "G": 0,
    "H": 0,
    "R": 0,
    "S": 0
}

# with open("hogwarts.csv", "r") as file:
#     # reader = csv.reader(file)
#     # next(reader)  # ヘッダ行を無視する
#     for row in reader:
#         house = row[1]  # カンマを手がかりに要素へ分解してある
#         houses[house] += 1

with open("hogwarts.csv", "r") as file:
    reader = csv.DictReader(file)  # ヘッダ行をキーの名前として利用する
    for row in reader:
        house = row["House"]  # キー名で参照できる
        houses[house] += 1


for house in houses:
    count = houses[house]
    print(f"{house}:{count}")
