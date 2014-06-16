#include "Data.h"
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