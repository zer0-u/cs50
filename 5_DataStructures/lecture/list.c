// 2023/01/18
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ヒープ領域に確保する
    int *list = malloc(8 * sizeof(int));

    free(list);
}