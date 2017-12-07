/* 顺序结构线性链表 */
#ifndef SLIST_H
#define SLIST_H

#define MAXSIZ 40
#define OK  1;
#define ERR 0;

typedef int Item;

typedef struct Node
{
    Item data[MAXSIZ];
    int length;
} Slist;

typedef int Status;




/**
 * 操作：   获取指定位置的数据
 * 操作前： slist指向一个已初始化的列表
 *          i插入的位置  从1算 
 *          item待接受指定位置的数据
 * 操作后： 获取成功返回OK,并把数据给item 否则ERR
 **/
Status getItem(const Slist slist, int i, Item * item);

/**
 * 操作：   在指定的位置插入数据到列表中
 * 操作前： slist指向一个已初始化的列表
 *          i插入的位置  从1算 
 *          item要插入的数据
 * 操作后： 插入成功返回OK,否则ERR
 **/
Status insterItem(Slist * slist, int i, Item item);

/**
 * 操作：   获取指定位置的数据
 * 操作前： slist指向一个已初始化的列表
 *          i插入的位置  从1算 
 *          item接收指定位置删除数据指针
 操作后：   删除成功返回OK,并把数据给item 否则ERR
 **/
Status delItem (Slist * slist, int i, Item * item);

#endif
