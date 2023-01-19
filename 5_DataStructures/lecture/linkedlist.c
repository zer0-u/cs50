// 2023/01/19
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    // 連結リスト用の変数を宣言し、NULLで初期化する
    node *list = NULL;

    // ノード1つ分のメモリを要求する
    // 変数nには確保したメモリの塊へのポインタが代入される
    node *n = malloc(sizeof(node));

    // メモリがきちんと確保された時は
    if (n != NULL)
    {
        (*n).number = 1;
    }
}