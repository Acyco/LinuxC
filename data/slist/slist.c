#include <stdio.h>
#include "slist.h"

Status getItem (const Slist slist, int i, Item * item)
{
    if(slist.length == 0 || i < 1 || i > slist.length )
    {
        return ERR;
    }
    *item = slist.data[i - 1];
    return OK;
}

Status insterItem (Slist * slist, int i, Item item)
{
    int j;
    if(slist->length == MAXSIZ)
    {
        return ERR;
    }
    if(i < 1 || i > slist->length + 1)
    {
        return ERR;
    }

    if (i <= slist->length)
    {
        // {1}  1 4           len:1 i:1 item :4 
        for (j = slist->length - 1; j >= i - 1; j--)
            slist->data[j + 1] = slist->data[j];
    }
    
    slist->data[i - 1] = item;
    slist->length++;
    return OK;
}

Status delItem (Slist * slist , int i, Item *item)
{
    int j;
    if (i < 1 || i > slist->length || slist->length == 0)
    {
        return ERR;
    }
    
    *item = slist->data[i - 1];
    if(i < slist->length)
    {
        for (j = i; j < slist->length; j++ )
            slist->data[j - 1] = slist->data[j];
    }
    slist->length--;
    return 0;
}


