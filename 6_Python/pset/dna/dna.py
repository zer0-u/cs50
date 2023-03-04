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


main()
