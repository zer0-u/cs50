// 2023/01/08
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    // for (int i = 0, n = strlen(s) + 1; i < n; i++)
    // {
    //     t[i] = s[i];
    // }

    strcpy(t, s);

    t[0] = toupper(t[0]);

    free(t);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}