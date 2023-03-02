from cs50 import get_float

while True:
    input = get_float("Change owed: ")
    if input >= 0:
        break

