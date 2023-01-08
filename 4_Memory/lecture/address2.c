// 2023/01/08
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    char c = s[0];
    char *p = &c;
    printf("%p\n", s);
    printf("%p\n", p);
}