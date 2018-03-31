#include <malloc.h>
#include <stdio.h>

int main() {
  int a[5] = {1, 2, 3, 4, 5}; // 数组长度固定
  int len;
  printf("输入需要分配的数组的长度：len=");
  scanf("%d", &len);

  int *pArr =
      (int *)malloc(sizeof(int) * len); // 强制转换，malloc() 返回第一个字节地址
  *pArr = 9;
  pArr[1] = 3;
  int i;
  for (i = 0; i < len; ++i) {
    printf("a[%d] = %d\n", i, *(pArr + i));
  }

  free(pArr);

  return 0;
}