// https://cs50.jp/x/2021/week2/problem-set/substitution-more-comfortable/
// 2022/11/15 -
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validate_args(int argc, string argv);
bool has_enough_length(string key);

int main(int argc, string argv[])
{

    if (validate_args(argc, argv))
    {
        printf("ERROR\n");
        return 1;
    }
}

bool validate_args(int argc, string argv)
{
    if (argc != 2)
    {
        return false;
    }
    return has_enough_length(argv[1]);
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