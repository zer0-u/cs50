
def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        n = int(input("Height: "))
        if n > 0:
            break
    return n


main()
