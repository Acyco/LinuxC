/* fdopen_example.c -- 使用fdopen函数 */
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
    int fd;
    FILE * stream;

    unlink ("test.txt");
    fd = open ("test.txt", O_CREAT | O_WRONLY, S_IREAD | S_IWRITE);
    stream = fdopen (fd, "w");
    if (stream == NULL)
        printf ("fdopen failed");
    else
    {
        fprintf (stream, "Hello World\n");
        fclose (stream);
    }
    printf ("the content of the test.txt is: \n" );
    system ("cat test.txt");
    return 0;
}

