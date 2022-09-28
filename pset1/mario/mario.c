#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("heights : ");
    }
    while (height < 0);

    int width = 1;
    for(int i = 0;i < height;i++)
    {
        for(int j =0; j<width;j++)
        {
            printf("#");
        }
        printf("\n");
        width++;
    }
}