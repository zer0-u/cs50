
import csv
import sys

if len(sys.argv) != 2:
    sys.exit("Usage: python tournament.py FILENAME")

teams = []
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)  # ヘッダ行をキーの名前として利用する
    for row in reader:
        team = {
            "team": row["team"],
            "rating": int(row["rating"])
            }
        teams.append(team)

for team in teams:
    print(team)
