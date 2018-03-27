#include"c1.h"

void fa(int a)
{
    a++;
    printf("在函数fa中：a = %d\n", a);
}
//标准C语言中没有引用类型
void fb(int &a)
{
    a++;
    printf("在函数fb中：a = %d\n", a);
}

int main()
{
    int n = 1;
    printf("在主进程中，调用函数fa之前：n = %d\n", n);
    fa(n);
    printf("在主进程中，调用函数fa之后，调用函数fb之前：n = %d\n", n);
    fb(n);
    printf("在主进程中，调用函数fb之后：n = %d\n", n);
    printf("%d", n);
}