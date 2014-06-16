﻿#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

void InitQueue(LINKQUEUE *pQ)
{
	pQ->front = (NODE *)malloc(sizeof(NODE));
	if (!pQ->front)
	{
		printf("动态内存分配失败!\n");
		exit(ERROR);
	}
	pQ->front->pNext = NULL;
	pQ->rear = pQ->front;

	return;
}

void DestroyQueue(LINKQUEUE *pQ)
{
	NODE *p = pQ->front;
	while (p)
	{
		pQ->front = p->pNext;
		free(p);
		p = pQ->front;
	}/*退出while循环时,front为NULL*/
	pQ->rear = NULL;

	return;
}

void ClearQueue(LINKQUEUE *pQ)
{
	NODE *p = pQ->front;
	NODE *q = NULL;
	
	if (!p)	/*如果队列不存在(即已经被销毁)*/
	{
		printf("队列已经被销毁,无法执行清空操作!\n");
		return;
	}
	q = p->pNext;

	while (q)
	{
		p = q->pNext;
		free(q);
		p = q;
	}
	pQ->front->pNext = NULL;
	pQ->rear = pQ->front;

	return;
}

BOOL QueueEmpty(const LINKQUEUE *pQ)
{
	if (pQ->front == pQ->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

size_t QueueLength(const LINKQUEUE *pQ)
{
	size_t len = 0;
	NODE *p = pQ->front;
	while (p && p->pNext)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

STATUS GetHead(const LINKQUEUE *pQ, Elem *e)
{
	if (pQ->front && pQ->front->pNext)/*若链式队列存在并且不为空*/
	{
		*e = pQ->front->pNext->data;
		return OK;
	}

	return FAILE;
}