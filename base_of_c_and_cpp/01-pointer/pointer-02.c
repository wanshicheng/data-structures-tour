#include<stdio.h>

int main()
{
    int i = 10;
    int *p = &i;
    printf("%d\n", p); // p保存地址，这里p保存了i的地址
    printf("%d\n", *p); // *p表示p指向的内容
    printf("%d\n", i);
    *p = 100;
    printf("%d\n", i);
    p = i;
    printf("%d\n", p);
    // printf("%d\n", *p); //对一个未做声明的地址直接进行访问当然会引发错误
    
    return 0;
}