#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = 0;
    do
    {
        start = get_int("Start size: ");
    }while(start < 9);

    // TODO: Prompt for end size
    int end = 0;
    do
    {
        end = get_int("End size: ");
    }while(end <= start);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int lamas = start;

    do
    {
        lamas = lamas + (lamas / 3) - (lamas / 4);
    }while(lamas < end);

    // TODO: Print number of years
    printf("Years: %i\n",years);
}