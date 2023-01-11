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

    for (int i = 0; i < 3; i++)
    {
        char c;
        fread(&c, sizeof(char), 1, input);
        fwrite(&c, sizeof(char), 1, output);
    }

    fclose(input);
    fclose(output);
}