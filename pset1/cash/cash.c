#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float owed = get_float("Change owed : ");
    int cents = round(owed * 100);
    printf("cents : %i\n", cents);
}