#include <malloc.h>
#include <stdio.h>

struct Student {
  int sid;
  int age;
};

struct Student *createStudent(void);

void showStudent(struct Student *);

int main() {
  struct Student *ps;
  ps = createStudent();
  showStudent(ps);
}

struct Student *createStudent() {
  struct Student *p = (struct Student *)malloc(sizeof(struct Student));
  p->sid = 100;
  (*p).age = 18;
  return p;
}

void showStudent(struct Student *p) { printf("%d %d", p->sid, p->age); }