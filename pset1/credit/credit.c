#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number = 0;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    int last_2 = (number % 100) / 10;
    int last_4 = (number % 10000) / 1000;
    int last_6 = (number % 1000000) / 100000;
    int last_8 = (number % 100000000) / 10000000;
    int last_10 = (number % 10000000000) / 1000000000;
    int last_12 = (number % 1000000000000) / 100000000000;
    int last_14 = (number % 100000000000000) / 10000000000000;
    int last_16 = (number % 10000000000000000) / 1000000000000000;
    printf("%i, %i, %i, %i, %i, %i, %i, %i\n",last_2, last_4, last_6, last_8, last_10, last_12, last_14, last_16);

    int check1 = last_2 * 2 + last_4 * 2 + last_6 * 2 + last_8 * 2 + last_10 * 2 + last_12 * 2 + last_14 * 2 + last_16 * 2;
    printf("check1 : %i\n", check1);
}