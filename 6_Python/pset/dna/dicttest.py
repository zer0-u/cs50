def main():
    sample = {
        "name": "AAA",
        "apple": 1,
        "banana": 1,
        "orange": 1,
        "peach": 1
    }
    keys = sample.keys()
    key_list = list(keys)
    sliced = key_list[1:]
    print(sliced)


main()
