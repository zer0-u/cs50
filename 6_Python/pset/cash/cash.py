from cs50 import get_float


def main():
    while True:
        input = get_float("Change owed: ")
        if input >= 0:
            break

    # セントに直す
    change = input * 100

    coins = [25, 10, 5, 1]
    count = 0

    for coin in coins:
        result = calc(change, coin)
        change = result["remain"]
        count += result["count"]

    print(count)


def calc(remain, coin):
    count = 0
    while remain >= coin:
        count += 1
        remain -= coin
    return {"remain": remain, "count": count}


main()
