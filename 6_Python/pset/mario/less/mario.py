from cs50 import get_int

height = get_int("Height: ")
for i in range(1, height+1):
    print(" "*(height-i), end="")
    print("#"*(i), end="")
    print()
