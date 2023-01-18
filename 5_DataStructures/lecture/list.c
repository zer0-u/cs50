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

    // 配列の要素数を増やしたいので領域を確保し直す
    list = malloc(4 * sizeof(int));
    // ↑だと8行目で確保したメモリへのポインタが失われ、
    // 0~2番目の要素も参照できなくなってしまう

    list[3] = 4;

    free(list);
}