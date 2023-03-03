from cs50 import get_string


def main():
    number = get_string("Number :")
    if not check_length(number):
        print('INVALID')
        return
    if not is_valid(number):
        print('INVALID')
        return
    print(check_header(number))


def check_length(number):
    return len(number) in [13, 15, 16]


def is_valid(number):
    sum = 0
    is_even = False
    for i in range(len(number), 0, -1):
        print(f'i: {i}, is_even: {is_even}')
        if is_even:
            elem = i*2
            if elem > 10:
                sum += (elem / 10)
                sum += (elem % 10)
            else:
                sum += elem
        else:
            sum += i
        is_even = not is_even

    return sum % 10 == 0


def check_header(number):
    header = number[:2]
    if header in ['34', '37']:
        return 'AMEX'
    elif header in ['51', '52', '53', '54', '55']:
        return 'MASTERCARD'
    elif header[0] == '4':
        return 'VISA'
    return 'INVALID'


main()
