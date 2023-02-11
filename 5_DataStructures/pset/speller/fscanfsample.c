#include <stdio.h>

int main(void)
{
    FILE *file = fopen("/dictionaries/small","r");
    if (file == NULL)
    {
        return 1;
    }
    char* word;
    while (fscanf(file, "%s", word))
    {
        printf("%s", word);
    }
}