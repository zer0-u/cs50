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

    // さらにもう1つ要素を追加する
    // 実際の処理はループ等を用いるとよい
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        // listだけを解放しても、2つ目の領域は解放されない
        free(list->next);
        // 先に解放すると2つ目の要素が迷子になるので注意
        // [重要] 解放済のメモリには触らない
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // 内容を表示する
    // 要素が隣同士だと保証できないのでforループは使えない
    // 変数tmpにnextフィールドの中身を代入し、NULLになる＝最後の要素に到達するまで繰り返す
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // 後片付け(地道)
    // free(list->next->next);
    // free(list->next);
    // free(list);

    // 後片付け(ちょっと複雑)
    while (list != NULL)
    {
        // 「次の」要素を変数tmpに代入する
        node *tmp = list->next;
        // 「現在の」要素を解放する
        free(list);
        // 要素を1つ詰める
        list = tmp;
    }
}