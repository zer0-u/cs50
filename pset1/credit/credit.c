#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    long number = 0;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    char num[256];
    sprintf(num,"%ld",number);

    printf("%c\n", num[1]);
}