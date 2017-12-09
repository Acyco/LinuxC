/* time_exp.c -- 时间处理函数的示例程序 */
#include <stdio.h>
#include <time.h>
#include <string.h>

int main (void)
{
    time_t timep;
    time (&timep);//读取时间，秒数
    printf ("ctime return: %s\n", ctime (&timep)); // 转换为字符串输出

    time_t timep1, timep2;
    time (&timep1);
    time (&timep2);
    printf ("%s \n", asctime (gmtime (&timep1))); // 转换为UCT时间， 并以字符串输出
    printf ("%s \n", asctime (localtime (&timep1))); // 转换为本地时间， 并以字符串输出

    char buff[128];
    memset (buff, '\0', 128);
    printf ("globle time:");
    strftime (buff, 128, "%z", gmtime (&timep1));
    printf ("TZ = %s\n", buff);

    printf ("local time:");
    strftime (buff, 128, "%z", localtime (&timep2));
    printf ("TZ = %s\n", buff);
    return 0;
}

