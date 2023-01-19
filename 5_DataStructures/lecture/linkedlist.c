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
        // 変数nが指している場所に移動し、numberフィールドに1を代入する
        // *は間接参照演算子
        // 括弧をつけて処理順序を明示している
        // (*n).number = 1;
        // ↑をより簡潔に書く糖衣構文
        n->number = 1;
        // 次のノードはまだないのでNULLで初期化しておく
        n->next = NULL;
        // listが1つ目のノードを指すようにポインタを代入する
        list = n;
    }
}