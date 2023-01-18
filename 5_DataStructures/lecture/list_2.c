// 2023/01/18
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // ヒープ領域に確保する
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1; // *list = 1;
    list[1] = 2; // *(list + 1) = 2;
    list[2] = 3; // *(list + 2) = 3;

    // 配列の要素数を増やしたいので領域を確保し直す
    // list = malloc(4 * sizeof(int));
    // ↑だと8行目で確保したメモリへのポインタが失われ、
    // 0~2番目の要素も参照できなくなってしまう

    // 別の変数にポインタを代入する
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // 4つの要素を持てる配列tmpに配列listの要素をコピーする
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    // 要素を追加する
    tmp[3] = 4;

    // 要素3個分のメモリの塊は解放する
    // 解放する前に代入し直すとメモリが確保され続けるので注意
    free(list);

    // ポインタを代入し直す
    list = tmp;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // listとtmpは同じ塊を指しているのでfree(tmp)でもOK
    free(list);
    return 0;
}