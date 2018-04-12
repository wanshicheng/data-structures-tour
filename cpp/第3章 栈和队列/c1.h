// c1.h （文件名）
#include <ctype.h>
#include <io.h>
#include <limits.h>
#include <malloc.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
// 函数结果状态代码。在严书第10页
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
// #define INFEASIBLE -1 没使用
// #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3，故去掉此行
typedef int Status;
typedef int Boolean;