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

    char num[];
    sprintf(num,"%ld",number);
    int size = sizeof(num)/sizeof(num[0]);
    printf("%i\n", size);
    printf("%c\n", num[1]);
}