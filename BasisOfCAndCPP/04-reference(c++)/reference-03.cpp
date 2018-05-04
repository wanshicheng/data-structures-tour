// 把引用作为返回值
#include <stdio.h>

float a[] = {1.1, 2.2, 3.3, 4.4, 5.5};

float &setValue(int i) {
  return a[i]; // 返回第 i 个元素的引用
}

// 要调用上面定义函数的主函数
int main() {
  printf("改变前的值\n");
  for (int i = 0; i < 5; i++) {
    printf("a[%d] = %f\n", i, a[i]);
  }
  setValue(1) = 10;
  float &x = setValue(3);
  x = 100;

  printf("改变后的值\n");
  for (int i = 0; i < 5; i++) {
    printf("a[%d] = %f\n", i, a[i]);
  }

  return 0;
}

// 当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。
int &func() {
  int q;
  //! return q; // 在编译时发生错误
  static int x;
  return x; // 安全，x 在函数作用域外依然是有效的
}