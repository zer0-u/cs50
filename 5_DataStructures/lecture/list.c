// 2023/01/19
#include <stdio.h>
#include <stdlib.h>

// nodeというstructを宣言し
// typedefを使って↑を「node」だけで示せるようにする
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    // 新しいノードを追加する
    // 17行目で宣言した変数nに代入されたポインタは変数listで保持できているので
    // 変数名は同じまま新たな領域を確保する
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        // 解放漏れに注意
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;

    // 1つ目の要素のnextフィールドに新しいnodeへのポインタを代入する
    list->next = n;
}