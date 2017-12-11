/* string_example.c */    
#include <stdio.h>
int main (int argc, char * argv[])
{
    FILE * fp = NULL;
    char str[100];

    if ((fp = fopen (argv[1], "r")) == NULL)
    {
        printf ("can not open!\n");
        return -1;
    }
    fgets (str, sizeof (str), fp);
    fputs (str, stdout);
    fclose (fp);
    return 0;
}
