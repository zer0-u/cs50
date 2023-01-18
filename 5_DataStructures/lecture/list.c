// 2023/01/18
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ヒープ領域に確保する
    int *list = malloc(3 * sizeof(int));
    if (list == null)
    {
        return 1;
    }

    list[0] = 1; // *list = 1;
    list[1] = 2; // *(list + 1) = 2;
    list[2] = 3; // *(list + 2) = 3;

    // 配列の要素数を増やす
    list = malloc(4 * sizeof(int));

    list[3] = 4;

    free(list);
}