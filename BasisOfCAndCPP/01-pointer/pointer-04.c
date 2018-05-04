#include<stdio.h>

void Change_Array(int *p)
{
    p[0] = -1; // p[0] == *p   p[2]==*(p+2)==*(a+2)==a[2]
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5}; //一维数组名是个指针常量，一维数组存放数组第一个元素的地址

    printf("%d\n", a);
    printf("%d\n", *a);
    printf("%d\n", a+1);
    printf("%d\n", *(a+1));
    printf("%d\n", *(a+10));
    Change_Array(a);
    printf("%d\n", a[0]);

    return 0;
}