#include <stdio.h>
#include <cs50.h>
#include <math.h>

int remove_coin(int,int);

int main(void)
{
    float owed = get_float("Change owed : ");
    int cents = round(owed * 100);

    int count_25 = remove_coin(cents, 25);

    int count_10 = remove_coin(cents, 10);

    int count_5 = remove_coin(cents, 5);

    int count_1 = remove_coin(cents, 1);
    int count = count_25 + count_10 + count_5 + count_1;
    printf("25 * %i + 10 * %i + 5 * %i + %i", count_25, count_10, count_5, count_1);
    printf("%i\n",count);
}

int remove_coin(int cents, int coin)
{
    int count = 0;
    while (cents >= coin)
    {
        cents -= coin;
        count++;
    }
    return count;
}