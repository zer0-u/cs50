#include <stdio.h>
#include <ctype.h>

// hash関数の中できちんと引数が参照できるか

unsigned int hash(const char *word)
{
    char top = tolower(word[0]);
    return top;
}

int main(void)
{
    char input[46] = "iTh";
    int code = hash(input);
    printf("%i\n", code);
}