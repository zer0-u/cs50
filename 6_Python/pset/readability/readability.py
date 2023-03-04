from cs50 import get_string


def main():
    text = get_string("Text: ")
    letter_count = count_letters(text)
    print(letter_count)
    word_count = count_words(text)
    print(word_count)


def count_letters(text):
    count = 0
    for l in text:
        if l.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for l in text:
        if l.isspace():
            count += 1
    return count


main()
