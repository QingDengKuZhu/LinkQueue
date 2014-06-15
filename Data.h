/*
**链式队列的数据结构
*/
#ifndef DATA_H
#define DATA_H

typedef int Elem;

typedef struct Node
{
	Elem data;	/*数据域*/
	struct Node *pNext;	/*指针域*/
}NODE;

typedef struct LinkQueue
{
	NODE *front;	/*队头,指向头结点*/
	NODE *rear;	/*队尾,指向尾部数据*/
}LINKQUEUE;

#endif