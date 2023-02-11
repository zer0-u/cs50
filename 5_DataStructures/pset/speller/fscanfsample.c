#include <stdio.h>

int main(void)
{
    FILE *file = fopen("dictionaries/small", "r");
    if (file == NULL)
    {
        printf("can not read");
        return 1;
    }
    char word[46];
    while (fscanf(file, "%s", word) != EOF)
    {
        printf("%s\n", word);
    }
    fclose(file);
}