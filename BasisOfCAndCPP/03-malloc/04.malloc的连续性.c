#include <stdio.h>
#include <malloc.h>

int main()
{
    int *ip = (int *)malloc(sizeof(int) * 10);
    double *dp = (double *)malloc(sizeof(double) * 10);
    printf("%p\n", ip);
    printf("%p\n", dp);
    printf("%d\n", (long)dp-(long)ip);
    ip = (int *)realloc(ip, sizeof(int) * 100);
    printf("%p\n", ip);
    printf("%p\n", dp);
    printf("%d\n", (long)dp-(long)ip);

    return 0;
}
