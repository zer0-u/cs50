#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("height : ");
    }
    while (height <= 0 || height > 8);

    int blocks = 1;
    for(int i = 0;i < height;i++)
    {

        int spaces = height-blocks;
        for(int j = 0;j<spaces;j++)
        {
            printf(" ");
        }
        for(int j = 0;j<blocks;j++)
        {
            printf("#");
        }
        printf("  ");
        for(int j = 0;j<blocks;j++)
        {
            printf("#");
        }
        blocks++;
        printf("\n");
    }
}