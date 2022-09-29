#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float owed = get_float("Change owed : ");
    int cents = round(owed * 100);
    printf("cents : %i\n", cents);
    int count_25 = 0;
    while(cents >= 25)
    {
        cents -= 25;
        count_25++;
    }

    int count_10 = 0;
    while(cents >= 10)
    {
        cents -= 10;
        count_10++;
    }

    int count_5 = 0;
    while(cents >= 5)
    {
        cents -= 5;
        count_5++;
    }

    int count_1 = 0;
    while (cents >= 1)
    {
        cents -= 1;
        count_1++;
    }
    int count = count_25 + count_10 + count_5 + count_1;
    printf("%i\n",count);
}