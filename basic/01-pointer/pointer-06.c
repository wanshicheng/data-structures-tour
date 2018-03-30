#include<stdio.h>

float a[] = {1.1, 2.2, 3.3, 4.4, 5.5};

float* setValue(int i)
{
    float *p = &a[i];
    return p;
}

int main()
{   
    float f;
    float *p;

    printf("改变前的值\n");
    for ( int i = 0; i < 5; i++ )
    {
        printf("a[%d] = %f\n", i, a[i]);
    }
    
    *setValue(1) = 10;
    p = setValue(3);
    *p = 100;
    *(p+1) = 200;
 
    printf("改变前的后\n");
    for ( int i = 0; i < 5; i++ )
    {
        printf("a[%d] = %f\n", i, a[i]);
    }
}