import csv

titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        

for title in sorted(titles):
    print(title)
