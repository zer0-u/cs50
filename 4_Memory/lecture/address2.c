// 2023/01/08
#include <stdio.h>
//#include <cs50.h>

int main(void)
{
    char *s = "HI!";
    char *p = &s[0];
    printf("%p\n", s);
    printf("%p\n", p);
}