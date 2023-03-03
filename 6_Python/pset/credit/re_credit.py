from cs50 import get_string
import re

# 正規表現の練習用
def main():
    number = get_string("Number :" )
    pattern = '^\d{13,16}'
    result = re.match(pattern,number)
    if result:
        print(f'{number} matched')
    else:
        print(f'{number} not matched')

main()