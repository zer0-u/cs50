from string import ascii_letters  # アルファベット
from itertools import product

for passcode in product(ascii_letters, repeat=4):
    print(*passcode)
