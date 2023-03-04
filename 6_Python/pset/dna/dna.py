from sys import argv
import csv


def main():
    # コマンドライン引数をチェック
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return
    # ファイル読み込み
    database = load_database(argv[1])
    sequence = load_sequence(argv[2])


def load_database(filename):
    list = []
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            list.append(row)
    return list


def load_sequence(filename):
    with open(filename, "r") as file:
        # 末尾の改行をrstripで取り除く
        return file.read().rstrip()


main()
