#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("height : ");
    }
    while (height < 0);

    int blocks = 1;
    for(int i = 0;i < height;i++)
    {

        int spaces = height-blocks;
        for(j = 0;j<spaces;j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}