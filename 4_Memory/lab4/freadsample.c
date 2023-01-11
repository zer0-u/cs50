#include <stdio.h>

int main(void)
{
FILE *input = fopen("cs50.txt", "r");
    if (input == NULL)
    {
        return 1;
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL)
    {
        fclose(input);
        return 1;
    }

    char c;
    while (fread(&c, sizeof(char), 1, input))
    {
        fwrite(&c, sizeof(char), 1, output);
    }

    fclose(input);
    fclose(output);
}