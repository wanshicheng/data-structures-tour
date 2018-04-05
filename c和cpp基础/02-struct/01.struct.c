#include <stdio.h>
#include <string.h>

struct Student {
  int sid;
  char name[64];
  int age;
};

int main() {
  struct Student s1 = {7, "Jack", 20};
  printf("%d %s %d\n", s1.sid, s1.name, s1.age);

  struct Student s2;
  s2.sid = 8;
  // s2.name = "bill"; // 错误
  strcpy(s2.name, "bill");
  s2.age = 21;
  printf("%d %s %d\n", s2.sid, s2.name, s2.age);

  printf("Student 的字节：%llu\n", sizeof(struct Student));
  printf("sid 的字节：%llu\n", sizeof(s1.sid));
  printf("name 的字节：%llu\n", sizeof(s1.name));
  printf("age 的字节：%llu\n", sizeof(s1.age));

  struct Student *ps;
  ps = &s1;
  ps->sid = 100; // ps->sid 等价于 (*ps).sid 等价于 s1.sid
  // ps->name[0] = "T";
  strcpy(ps->name, "Lily");
  ps->age = 19;
  printf("%d %s %d\n", s1.sid, s1.name, s1.age);

  return 0;
}