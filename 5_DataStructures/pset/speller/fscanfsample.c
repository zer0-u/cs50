#include <stdio.h>

int main(void)
{
    FILE *file = fopen("dictionaries/small", "r");
    if (file == NULL)
    {
        printf("can not read");
        return 1;
    }
    char *word = NULL;
    while (fscanf(file, "%s", word))
    {
        printf("%s", word);
    }
}