#include <stdio.h>

int main(void)
{
    FILE *input = fopen("cs50.txt", "r");
    if (input == NULL)
    {
        return 1;
    }

    FILE *output = fopen("1111.txt", "w");
    if (output == NULL)
    {
        fclose(input);
        return 1;
    }

    char c;
    for (int i = 0; i < 5; i++)
    {
        fread(&c, sizeof(char), 1, input);
        printf("%c", c);
    }

    while (fread(&c, sizeof(char), 1, input))
    {
        fwrite(&c, sizeof(char), 1, output);
    }

    fclose(input);
    fclose(output);
}