from string import digits, ascii_letters, punctuation  # 句読点
from itertools import product  # たくさんの数の直積を計算する関数

for passcode in product(digits, repeat=4):
    print(*passcode)
