/* 使用顺序结构 */
#include <stdio.h>
#include "slist.h"

int main(void)
{
    Slist slist;
    Item item = 0;
    int i;

    slist.length = 0;
    for (i = 1; i <= 5; i++)
    {
        item = i * i;
        insterItem(&slist, 1, item); 
    }
    
    
    for (i = 1; i <= slist.length; i++)
    {
        getItem (slist, i, &item);
        printf ("%d\n", item);
    }

    getItem (slist, 2, &item);
    printf ("getItem 2 : %d\n", item);

    delItem (&slist, 3, &item);
    printf ("delItem 3: %d\n", item);
    

    for (i = 1; i <= slist.length; i++)
    {
        getItem (slist, i, &item);
        printf ("%d\n", item);
    }
    puts ("Bye~~");
    return 0;
}
