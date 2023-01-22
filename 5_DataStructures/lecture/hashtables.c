// 2023/01/22
#include <stdio.h>
#include <cs50.h>

// 例
const int LONGEST_WORD = 100;

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
    node *hash_table[NUMBER_OF_BUCKETS];
}