from sys import argv
import csv

def main():
    # コマンドライン引数をチェック
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return
    load_dictionary(argv[1])


def load_dictionary(filename):
    with open(filename,"r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            print(len(row))



main()
