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

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //要素4個分にリサイズする(第1引数はリサイズしたい塊へのポインタ)
    list = realloc(list, 4 * sizeof(int));
    if (list == NULL)
    {
        free(list);
        return 1;
    }

    // 4つの要素を持てる配列tmpに配列listの要素をコピーする
    // ※ reallocを使う場合は不要(暗黙のうちに実行される)
    // for (int i = 0; i < 3; i++)
    // {
    //     tmp[i] = list[i];
    // }

    // 要素を追加する
    list[3] = 4;

    // 要素3個分のメモリの塊は解放する
    // 解放する前に代入し直すとメモリが確保され続けるので注意
    // ※ reallocを使う場合は不要(暗黙のうちに実行される)
    // free(list);

    // ポインタを代入し直す
    // list = tmp;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // listとtmpは同じ塊を指しているのでfree(tmp)でもOK
    free(list);
    return 0;
}