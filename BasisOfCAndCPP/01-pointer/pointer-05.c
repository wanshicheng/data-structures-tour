#include<stdio.h>

void Show_Array(int *p, int len)
{
    int i = 0;
    printf("************\n");
    for(i; i<len; ++i)
        printf("%d\n", p[i]);
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    printf("%d\n", a[0]);
    printf("%d\n", a[2]);
    Show_Array(a, 5); // a等价于&a[0],而&a[0]本身就是int * 类型

    return 0;
}