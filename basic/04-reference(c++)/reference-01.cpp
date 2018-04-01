#include <stdio.h>
 
int main ()
{
   int i = 1;
   int & r = i;
   int * p1 = &r; // c++的指针最好提前初始化
   int * p2 = &i;

  
   printf("%d\n", r);
   printf("%d\n", &r);
   printf("p1 的指向的地址为 %d\n", p1);
   printf("p1 的值为 %d\n", *p1);
   printf("%d\n", p2);
   printf("%d\n", i);
   r = r + 1;
   printf("%d\n", i);

   return 0;
}