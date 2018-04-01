/**
 * (1)将变量名作为实参和形参。这时传给形参的是变量的值，
 * 传递是单向的。如果在执行函数期间形参的值发生变化，
 * 并不传回给实参。因为在调用函数时，形参和实参不是同一个存储单元。// 同 c
 *
 *  (2) 传递变量的指针。形参是指针变量，实参是一个变量的地址，
 * 调用函数时，形参(指针变量)指向实参变量单元。
 * 这种通过形参指针可以改变实参的值。// 同 c
 * 
 * (3) C++提供了 传递变量的引用。
 * 形参是引用变量，和实参是一个变量，调用函数时，
 * 形参(引用变量)指向实参变量单元。这种通过形参引用可以改变实参的值。
 *
**/
#include<stdio.h>
 
void cpp_swap(int &x, int &y);
void c_swap(int *x, int *y);
 
int main ()
{
    int a = 1;
    int b = 2;
    int c = 10;
    int d = 20;

    printf("交换前，a 的值 %d\n", a);
    printf("交换前，b 的值 %d\n", b);
    cpp_swap(a, b);
    printf("交换后，a 的值 %d\n", a);
    printf("交换后，b 的值 %d\n", b);

    printf("交换前，c 的值 %d\n", c);
    printf("交换前，d 的值 %d\n", d);
    c_swap(&c, &d);  // C++之所以增加引用类型， 主要是把它作为函数参数，以扩充函数传递数据的功能。
    printf("交换后，c 的值 %d\n", c);
    printf("交换后，d 的值 %d\n", d);
 
   return 0;
}
 
void cpp_swap(int &x, int &y)
{
    int temp;
    temp = x; /* 保存地址 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 x 赋值给 y  */

    return;
}

void c_swap(int *x, int *y)
{
    int temp;
    temp = *x; /* 保存地址 x 的值 */
    *x = *y;    /* 把 y 赋值给 x */
    *y = temp; /* 把 x 赋值给 y  */

    return;
}