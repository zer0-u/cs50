from cs50 import get_string

text = get_string("Text: ")

letter_count = 0
for l in text:
    if l.isalpha():
        letter_count += 1


print(letter_count)
