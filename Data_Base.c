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

	pQ->rear = pQ->front;

	return;
}

