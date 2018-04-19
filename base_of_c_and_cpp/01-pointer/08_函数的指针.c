#include <stdio.h>
void foo( void )
{
    printf("date: %s\n", __DATE__ );
}
int main()
{
    void (*p)( void ) ;
     
    p=foo ; //指向某个函数
    p();//调用方法1
    (*p)(); //调用方法2
    foo();
}