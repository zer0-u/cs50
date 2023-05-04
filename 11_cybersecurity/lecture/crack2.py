from string import digits, ascii_letters, punctuation  # 句読点
from itertools import product  # たくさんの数の直積を計算する関数

for passcode in product(ascii_letters + digits + punctuation, repeat=8):
    print(*passcode)
