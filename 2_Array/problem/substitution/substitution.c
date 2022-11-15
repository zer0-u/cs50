// https://cs50.jp/x/2021/week2/problem-set/substitution-more-comfortable/
// 2022/11/15 -
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("ERROR\n");
        return 1;
    }
}

bool has_enough_length(string key)
{
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        if (length < 26)
        {
            return false;
        }
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}