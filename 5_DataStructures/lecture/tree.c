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

    // 一時変数nを使って1つのノードを生成・初期化
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
    // 一時変数nは使い回す
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        // TODO 確保済のメモリを解放
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;

    // 根の左側に保持
    tree->left = n;

    // 要素を1つ生成・初期化
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        // TODO 確保済のメモリを解放
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;

    // 根の右側に保持
    tree->right = n;

    // 木構造を出力
    print_tree(tree);

    // 確保したメモリをすべて解放
    free_tree(tree);
}

void free_tree(node *root)
{
    // ベースケース
    if (root == NULL)
    {
        return;
    }
    // 自分が持っているノードを先に解放する
    free_tree(root->left);
    free_tree(root->right);
    // 自分自身を解放する
    free(root);
}

void print_tree(node *root)
{
    // ベースケース
    if (root == NULL)
    {
        return;
    }
    // 再帰を使っている
    // 左側をprintする
    print_tree(root->left);
    // 自分自身が持つnumberを出力する
    printf("%i\n", root->number);
    // 右側をprintする
    print_tree(root->right);
    // 逆順にprintしたい時はrightとleftを入れ換える
}

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        // treeがない=numberもない=探しものは見つからない
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
}