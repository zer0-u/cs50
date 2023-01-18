// 2023/01/18
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // スタック領域に確保する
    int list[3];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}