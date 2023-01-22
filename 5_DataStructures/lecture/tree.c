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
    node *tree = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
}

void free_tree(node *root)
{
}

void print_tree(node *root)
{
}