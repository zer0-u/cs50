from cs50 import get_string
import re


def main():
    number = get_string("Number :")
    check_header(number)
    if not check_length(number):
        print('INVALID')
        return


def check_length(number):
    return len(number) in [13, 15, 16]


def check_header(number):
    header = number[:2]
    pattern = '(34|37)'
    return re.match(pattern, header)


main()
