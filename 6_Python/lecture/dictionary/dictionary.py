# 2023/02/20

words = dict()


def check(word):
    if word in words:
        return True
    else:
        return False


def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    file.close()
    return True

def size():
    return len(words)