from sys import argv
import csv

def main():
    # コマンドライン引数をチェック
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return
    database = load_database(argv[1])




def load_database(filename):
    list =[]
    with open(filename,"r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            list.append(row)
    return list



main()
