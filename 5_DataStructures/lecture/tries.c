// 2023/01/22
#include <stdio.h>
#include <stdbool.h>

const int SIZE_OF_ALPHABET = 26;

typedef struct node
{
    // 終端の場合はtrue
    bool is_word;
    // それぞれのノードは最大で26個の子を持つ
    struct node *children[SIZE_OF_ALPHABET];
} node;

int main(void)
{
}