#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    string input_key = argv[1];
    if (!isdigit(input_key))
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    int key = atoi(input_key);
    printf("%i\n", key);
}