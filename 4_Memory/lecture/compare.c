// 2023/01/08
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");
    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}