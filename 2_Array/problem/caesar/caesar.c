#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
bool key_is_digit(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    string input_key = argv[1];
    if (!key_is_digit(input_key))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    int key = atoi(input_key);
    printf("%i\n", key);
}

bool key_is_digit(string input)
{
    
    return false;
}