#include<stdio.h>

void f1(int i)
{
    i = 10;
    printf("在 f1 内 i 的值是 %d\n", i);
}

void f2(int *i)
{
    *i = 10;
    printf("在 f2 内 i 的值是 %d\n", i);
    printf("在 f2 内 *i 的值是 %d\n", *i);
}

int main()
{
    int i = 1;
    f1(i);
    printf("在 main 内 i 的值是 %d\n", i);
    f2(&i);
    printf("在 main 内 i 的值是 %d\n", i);

    return 0;
}