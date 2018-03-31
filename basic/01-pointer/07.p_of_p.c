/**
 * 指针的指针
 **/
#include <stdio.h>

int main() {
  int i;
  int *pInt;
  int **ppInt;

  i = 100;

  /* 获取 var 的地址 */
  pInt = &i;

  /* 使用运算符 & 获取 ptr 的地址 */
  ppInt = &pInt;

  /* 使用 pptr 获取值 */
  printf("i 的值为 %d\n", i);
  printf("*pInt 的值为 %d\n", *pInt);
  printf("**ppInt 的值为 %d\n", **ppInt);

  return 0;
}