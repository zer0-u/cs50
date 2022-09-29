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
    printf("%i, %i, %i, %i\n",last_2, last_4, last_6, last_8);
}