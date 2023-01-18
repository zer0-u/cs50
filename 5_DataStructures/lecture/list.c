// 2023/01/18
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ヒープ領域に確保する
    int *list = malloc(8 * sizeof(int));
    if (list == null)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    free(list);
}