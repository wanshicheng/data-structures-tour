#include<stdio.h>

int main()
{
    int * p; // p是个变量名字，int *表示该p变量只能存储int类型变量地址，也是p的类型
    int i = 10;
    
    printf("%d\n", p);
    printf("%d\n", *p);
    printf("%d\n", i);

    return 0;
}