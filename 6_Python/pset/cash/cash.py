from cs50 import get_float


def main():
    while True:
        input = get_float("Change owed: ")
        if input >= 0:
            break

    # セントに直す
    input *= 100

    count = 0
    # quarter(25)
    result = calc(input, 25)
    input = result["remain"]
    count += result["count"]

    # dime(10)
    result = calc(input, 10)
    input = result["remain"]
    count += result["count"]

    # nickel(5)
    result = calc(input, 5)
    input = result["remain"]
    count += result["count"]

    # penny(1)
    result = calc(input, 1)
    input = result["remain"]
    count += result["count"]
    print(count)


def calc(remain, coin):
    count = 0
    while remain >= coin:
        count += 1
        remain -= coin
    return {"remain": remain, "count": count}


main()
