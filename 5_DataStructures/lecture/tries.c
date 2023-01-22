// 2023/01/22
#include <stdio.h>
#include <cs50.h>

const int SIZE_OF_ALPHABET = 26;

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
} node;

int main(void)
{
}