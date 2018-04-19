#include <stdio.h>
#include <string.h>

struct Student {
  int sid;
  char name[64];
  int age;
};

void setStudent(struct Student *ps, int sid, char name[64], int age);
void showStudent(struct Student ps);

int main() {
  struct Student s1; // 已经分配了空间，但是是垃圾值
  printf("%d %s %d\n", s1.sid, s1.name, s1.age);
  setStudent(&s1, 50, "Ben", 22);
  printf("%d %s %d\n", s1.sid, s1.name, s1.age);
  showStudent(s1); // 传输的数据太多了，耗时间
}

void setStudent(struct Student *ps, int sid, char name[64], int age) {
  (*ps).sid = sid;
  strcpy((*ps).name, name);
  ps->sid = sid;
}

void showStudent(struct Student s) {
  printf("%d %s %d\n", s.sid, s.name, s.age);
}