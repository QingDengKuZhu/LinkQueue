/**********************
**链式队列的基本操作.
***********************/
#ifndef DATA_BASE_H
#define DATA_BASE_H

#include "Main_First.h"
#include "Data.h"

/*
pQ为指向链式队列的指针,且pQ不为NULL.
*/

/*构造一个空的链式队列.*/
void InitQueue(LINKQUEUE *pQ);

/*销毁链式队列.*/
void DestroyQueue(LINKQUEUE *pQ);

/*将链式队列清空.*/
void ClearQueue(LINKQUEUE *pQ);

/*判断链式队列是否为空.若为空,函数返回TRUE;否者函数返回FALSE.*/
BOOL QueueEmpty(const LINKQUEUE *pQ);

/*返回链式对列的长度*/
size_t QueueLength(const LINKQUEUE *pQ);

/*获取队头元素.若成功,函数返回OK,*e保存队头元素;否者返回FAILE,*e无定义.*/
STATUS GetHead(const LINKQUEUE *pQ, Elem *e);

/*在队尾插入元素v.若成功插入,函数返回OK;否者,函数返回FAILE.*/
STATUS InsertQueue(LINKQUEUE *pQ, const Elem v);

/*在队头删除元素,若成功删除,函数返回ok, *e保存删除值;否者函数返回FAIlE,*e无定义*/
STATUS DeleteQueue(LINKQUEUE *pQ, Elem *e);

/*遍历输出链式对列.*/
void TraveQueue(const LINKQUEUE *pQ);

#endif