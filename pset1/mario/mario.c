#include <stdio.h>
#include <cs50.h>

void show(int, string);
void print_blocks(int);
void print_spaces(int);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("height : ");
    }
    while (height <= 0 || height > 8);

    int blocks = 1;
    for (int i = 0; i < height; i++)
    {

        int spaces = height - blocks;
        print_spaces(spaces);
        print_blocks(blocks);
        printf("  ");
        print_blocks(blocks);
        blocks++;
        printf("\n");
    }
}

void print_blocks(int blocks)
{
    show(blocks, "#");
}

void print_spaces(int spaces)
{
    show(spaces, " ");
}

void show(int num, string type)
{
    for (int j = 0; j < num; j++)
    {
        printf(type);
    }
}