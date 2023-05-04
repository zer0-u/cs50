// 2022/12/25
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    int c = n;
    printf("%p\n", p);
    printf("n: %p\n", &n);
    printf("c: %p\n", &c);
    printf("%i\n", *p);
}