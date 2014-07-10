#include "Test.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void gotoxy(const short x, const short y)
{
	COORD pos;	/*COORD在windows.h中定义*/
	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); /* 设置光标位置 */

	return;
}


void Menu(void)
{
	system("cls");
	gotoxy(10, 5);                        /*在文本窗口中设置光标*/
	printf("			链式队列测试			");
	gotoxy(8, 8);
	printf("-----------------------------Menu-----------------------------\n");
	gotoxy(8, 9);
	printf("| 1.入队                     2.输出队列                  |\n");
	gotoxy(8, 10);
	printf("| 3.出队                     4.输出队长                  |\n");
	gotoxy(8, 11);
	printf("| 5.清空                     6.队头                      |\n");
	gotoxy(8, 12);
	printf("| 7.队列是否为空             8.销毁队列                  |\n");
	gotoxy(8, 13);
	printf("--------------------------------------------------------------\n");
	
    return;
}

size_t InputPos(const char notice[])
{
	int pos;		/*保存待输入的位序*/
	unsigned n;		/*保存scanf的返回值*/
	
	do 
	{
		printf(notice);
		n = scanf("%d", &pos);
		fflush(stdin);

		/*判断输入的位序是否在合理的范围内*/
		if (pos<1 || n!=1)
		{
			printf("位序必须大于0!!!\n");
		}
	} while (pos<1 || n!=1);

	return (size_t)pos;
}

int InputValue(const char notice[])
{	
	int e;
	unsigned n;

	do 
	{
		printf(notice);
		n = scanf("%d", &e);
		fflush(stdin);

		if (n != 1)
		{
			printf("请输入满足条件的数值!\n");
		}

	} while (n!=1);
	
	return e;
}