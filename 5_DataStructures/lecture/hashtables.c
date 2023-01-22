// 2023/01/22
#include <stdio.h>
#include <cs50.h>

// 例
const int LONGEST_WORD = 100;
const int NUMBER_OF_BUCKETS = 26;

// ハッシュテーブルで管理する要素
typedef struct node
{
    // 納めたい値そのもの
    // stringはないので適当な長さのchar型の配列を用意する
    // LONGEST_WORDは「これだけあれば多分大丈夫だろう」という字数
    // +1はヌル文字の分
    char word[LONGEST_WORD + 1];
    struct node *next;
}

int main(void)
{
    // ハッシュテーブルそのものを表す変数
    // 連結リストの先頭を集めたもの
    // NUMBER_OF_BUCKETSは概念的にはハッシュの数を表す
    node *hash_table[NUMBER_OF_BUCKETS];

    // ハッシュ関数
    // 要素が配置される場所を求める関数
    // 今回はアルファベット1文字目のASCIICODE
}