from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height in range(0, 9):
        break
    print("input integer(0-8)")

for i in range(1, height+1):
    print(" "*(height-i), end="")
    print("#"*(i), end="")
    print()
