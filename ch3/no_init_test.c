/* no_init_test.c -- 未初始化变量 */ 
#include <stdio.h>
int main (void)
{
    int x;
    if (x == 0)
        printf ("X is zero\n");
    else
        printf ("X isnot zero\n");
    return 0;
}

