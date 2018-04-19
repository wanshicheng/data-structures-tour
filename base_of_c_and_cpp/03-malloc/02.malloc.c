#include <stdio.h>

int f();

int main() {
  int i = 10;
  i = f();

  for (i = 0; i < 2000; ++i)
    f();
}

int f() {
  int f = 1;
  return f;
}