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

    
}