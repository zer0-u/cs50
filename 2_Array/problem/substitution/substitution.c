// https://cs50.jp/x/2021/week2/problem-set/substitution-more-comfortable/
// 2022/11/15 -
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validate_args(int argc, string argv);
bool validate_key(string key);

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
    return validate_key(argv[1]);
}

bool validate_key(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        return false;
    }

    int checksum = 0;
    for (int i = 0; i < length; i++)
    {
        char elem = key[i];
        if (!isalpha(elem))
        {
            return false;
        }
        checksum += elem;
    }
    return true;
}