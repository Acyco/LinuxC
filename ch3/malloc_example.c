/* malloc_example.c -- malloc/free 例子 */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[], char * envp[])
{
    int count;
    int * array;
    if ((array = (int *) malloc (10 * sizeof (int))) == NULL)
    {
        printf ("malloc memory unsuccessful\n");
        exit(1);
    }
    for (count = 0; count < 10; count++)
    {
        *array = count;
        array++;
    }
    for (count = 9; count >= 0; count--)
    {
        array--;
        printf ("%4d", *array);
    }
    printf ("\n");
    free (array);
    array = NULL;
    return 0;
}
