// https://cs50.jp/x/2021/week2/problem-set/substitution-more-comfortable/
// 2022/11/15 -
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validate_args(int argc, string argv[]);
bool validate_key(string key);

int main(int argc, string argv[])
{

    if (!validate_args(argc, argv))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    string input = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        char elem = input[i];
        char output;
        if (islower(elem))
        {
            output = tolower(key[elem - 'a']);
        }
        if (isupper(elem))
        {
            output = toupper(key[elem - 'A']);
        }
        printf("%c", output);
    }
    printf("\n");
}

bool validate_args(int argc, string argv[])
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
        checksum += tolower(elem);
    }
    // asciicodeでa(97)からz(122)を足した値が2847
    return checksum == 2847;
}