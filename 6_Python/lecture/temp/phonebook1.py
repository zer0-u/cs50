import csv
from cs50 import get_string

name = get_string("Name: ")
number = get_string("Number: ")

# file = open("phonebook.csv", "a")
with open("phonebook.csv", "a"):

    writer = csv.writer(file)
    writer.writerow([name, number])

# file.close()
