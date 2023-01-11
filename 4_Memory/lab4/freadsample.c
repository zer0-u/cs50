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
    int i = 0;
    while (fread(&c, sizeof(char), sizeof(char), input))
    {
        if (i > 5)
        {
            c = 'a';
        }
        fwrite(&c, sizeof(char), sizeof(char), output);
        i++;
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     char c;
    //     fread(&c, sizeof(char), sizeof(char), input);
    //     if (i < 5)
    //     {
    //         c = 'a';
    //     }
    //     else
    //     {
    //     }
    //     fwrite(&c, sizeof(char), sizeof(char), output);
    // }

    fclose(input);
    fclose(output);
}