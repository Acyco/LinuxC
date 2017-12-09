/* realloc_example.c -- realloc_example 例子 */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[], char * envp[])
{
    int input;
    int n;
    int *numbers1;
    int *numbers2;

    numbers1 = NULL;
    if ((numbers2 = (int *) malloc (5 * sizeof (int))) == NULL)
    {
        printf ("malloc memory unsuccessful\n");
        numbers2 = NULL;
        exit(1);
    }
    for (n = 0; n < 5; n++)
    {
        *(numbers2+n) = n;
        printf ("numbers2's data: %d \n", *(numbers2 + n));
    }

    printf ("Enter an integer value you want to realloc (enter 0 to stop)\n");

    scanf ("%d", &input);

    numbers1 = (int *) realloc (numbers2, (input + 5) * sizeof (int));
    if(numbers1 == NULL)
    {
        printf ("Error (re)allocating memory");
        exit(1);
    }
    for (n = 0; n < 5; n++)
    {
        printf ("the numbers1's data copy from numbers2: %d\n", *(numbers1 +n));
    }
    for (n = 0; n < input; n++)
    {
        *(numbers1+5+n) = n * 2;
        printf ("number1's new data: %d\n", *(numbers1 + 5 + n));
    }
    printf ("\n");
    free (numbers1);
        // free (numbers2);     不能再释放 在进行realloc 已经释放内存了
    numbers1 = NULL;
    return 0;
}

