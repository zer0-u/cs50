from sys import argv
import csv

def main():
    # コマンドライン引数をチェック
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return
    db_filename = argv[1]
    sequence_filename=argv[2]

    # データベースを読み込む
    with open(db_filename,"r") as db_file:
        db_reader = csv.DictReader(db_file):
        for row in db_reader:
            name = row["name"]
            



main()
