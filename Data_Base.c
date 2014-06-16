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
	while (!p)
	{
		pQ->front = p->pNext;
		free(p);
		p = pQ->front;
	}/*退出while循环时,front为NULL*/
	pQ->rear = NULL;

	return;
}