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

    # 今回の検証で用いるSTRの一覧を生成
    strs = select_str(database)

    # sequenceに含まれるSTRの回数を数える
    target = {}
    for str in strs:
        count = count_str(sequence, str)
        target[str] = count

    # databaseと照合する
    for db in database:
        if is_same(db, target, strs):
            print(db['name'])
            return
    print("No match")


def is_same(db, target, strs):
    for str in strs:
        if int(db[str]) != target[str]:
            return False
    return True


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


def select_str(database):
    # 今回の検証で用いるSTRの一覧を作る
    sample = database[0]
    keys = sample.keys()
    key_list = list(keys)
    # 先頭はnameなので2番目の要素から返す
    return key_list[1:]


def count_str(sequence, str):
    seq_len = len(sequence)
    str_len = len(str)
    count = 0
    max_repeat = 0
    i = 0
    while i < seq_len:
        # 部分文字列がSTRと一致したら
        if sequence[i:i+str_len] == str:
            # 繰り返し回数を1増やす
            count += 1
            # iをSTRの文字数の分だけ飛ばす
            i += str_len
        else:  # 一致しない=繰り返しが終了したら
            # 最大繰り返し回数を更新する
            if count > max_repeat:
                max_repeat = count
            i += 1
    return max_repeat


main()
