from cs50 import get_float

while True:
    input = get_float("Change owed: ")
    if input >= 0:
        break

# セントに直す
input *=100

# quarter(25)

# dime(10)

# nickel(5)

# penny(1)
