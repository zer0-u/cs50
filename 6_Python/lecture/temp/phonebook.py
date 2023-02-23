from cs50 import get_string

people = {
    "Carter": "1111",
    "David": "2222"
}

name = get_string("Name: ")
if name in people:
    number = people[name]
    print(f"Number: {number}")
