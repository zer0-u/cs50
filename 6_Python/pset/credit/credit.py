from cs50 import get_string
import re

def main():
    number = get_string("Number :" )
    pattern = '^\d{13,16}'
    result = re.match(pattern,number)
    if result:
        print(f'{number} matched')
    else:
        print(f'{number} not matched')

def check_length(number):
    return len(number) in [13,15,16]

main()