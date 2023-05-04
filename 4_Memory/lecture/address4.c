// 2023/01/08
#include <stdio.h>
// #include <cs50.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    printf("%i\n", *numbers);
    printf("%i\n", *(numbers + 1));
    printf("%i\n", *(numbers + 2));
    printf("%i\n", *(numbers + 3));
    printf("%i\n", *(numbers + 4));
    printf("%i\n", *(numbers + 5));
    printf("%i\n", *(numbers + 6));
}