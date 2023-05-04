from string import digits  # 10進数の数字
from itertools import product  # たくさんの数の直積を計算する関数

for passcode in product(digits, repeat=4):
    print(*passcode)
