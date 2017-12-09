/* mem_test.c -- 查看代码中各数据的存储位置 */
#include <stdio.h>
#include <stdlib.h>
int a = 0;                  // a在全局已初始化数据区
char * p0;                  // p0在BBS区（未初始化全局变量）
int main (void)
{
    int b;                  // b在栈区
    char s[] = "abc";       // s在栈区 “abc”在已初始化数据区
    char *p1, *p2;          // p1 p2 在栈区
    char *p3 = "123456";    // 123456\0 在已初始化数据区，p3在栈区
    static int c = 0;       // c为全局（静态）数据，存在于已初始化数据区
    p1 = (char *) malloc (10);  // 分配得来的10字节的区域在堆区
    p2 = (char *) malloc (20);  // 分配得来的20字节的区域在堆区
    printf ("a = %p\n",  &a);
    printf ("p0 = %p\n",  p0);
    printf ("b = %p\n",  &b);
    printf ("s = %p\n",  s);
    printf ("p1 = %p\n",  p1);
    printf ("p2 = %p\n",  p2);
    free (p1);
    free (p2);
    p1 = NULL;
    p2 = NULL;
    return 0;
}

