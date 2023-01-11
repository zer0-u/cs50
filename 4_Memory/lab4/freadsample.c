#include <stdio.h>

int main(void)
{
    FILE *file = fopen("cs50.txt", "r");
    if (file != NULL)
    {
        char c;
        while (fread(&c, sizeof(char), 1, file))
        {
            printf("%c", c);
        }
        fclose(file);
    }
}