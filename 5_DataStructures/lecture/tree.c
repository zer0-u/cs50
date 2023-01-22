// 2023/01/22
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

void free_tree(node *root);
void print_tree(node *root);

int main(void)
{
    // 木構造そのものを保持する変数を宣言
    node *tree = NULL;

    // 1つのノードを生成・初期化
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;

    // 根としてノードを保持する
    tree = n;

    // 新しいノードを生成・初期化
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;
}

void free_tree(node *root)
{
}

void print_tree(node *root)
{
}