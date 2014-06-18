/**********************
**主函数, 测试
***********************/

#include "Main_First.h"
#include "Data.h"
#include "Data_Base.h"
#include "Test.h"
#include <time.h> /*随机数*/

int main(void)
{
	int select;		/*保存选择变量*/
	size_t pos;		/*位序*/
	Elem e;			/*保存从函数返回的结点的值*/
	Elem v;			/*保存传递给函数的结点的值*/
	
	size_t i= 0;
	LINKQUEUE Q;
	InitQueue(&Q);
	srand((int)time(NULL));
	while (i < 10)
	{
		InsertQueue(&Q, rand()%20);
		++i;
	}

	while (1)	/*while_@1*/
	{
		if (!Q.front)
		{
			printf("队列不存在!\n");
			break;
		}

		system("cls");
		Menu();

		printf("请输入您的选择(1~10):");
		scanf("%d", &select);
		getchar();

		switch (select)	/*switch_@1*/
		{
		case 1:			/*入队*/
			v = InputValue("入队元素为:");
			if (FAILE == InsertQueue(&Q, v))
			{
				printf("入队失败!\n");
			}
			else
			{
				printf("入队成功!\n");
			}
			
			getchar();
			break;
		case 2:			/*输出队列*/
			printf("队列为:");
			TraveQueue(&Q);
			
			getchar();
			break;
		case 3:			/*出队*/
			if (OK == DeleteQueue(&Q, &e))
			{
				printf("出队成功,删除的元素是%d!\n", e);
			}
			else
			{
				printf("删除失败!\n");
			}

			getchar();
			break;

		case 4:			/*输出队列的长度*/
			printf("表长为: %d \n", QueueLength(&Q));
			
			getchar();
			break;

		case 5:			/*清空队列*/
			ClearQueue(&Q);
			printf("该表已经清空!\n");
			
			getchar();
			break;

		case 6:			/*返回队头元素*/
			if (OK == GetHead(&Q, &e))
			{
				printf("该结点为:%d\n", e);
			}
			else
			{
				printf("不存在!\n");
			}

			getchar();	
			break;

		case 7:			/*判断队列是否为空*/
			if (QueueEmpty(&Q) == TRUE)
			{
				printf("队列为空!\n");
			}
			else
			{
				printf("队列非空!\n");
			}

			getchar();	
			break;
		
		case 8:			/*销毁队列*/
			DestroyQueue(&Q);
			printf("队列已删除!\n");

			getchar();	
			break;
		
		default:
			printf("请重新选择!\n");
			
			getchar();
			break;
		}/*switch_@1*/

	}	/*while_@1*/
	
	return EXIT_SUCCESS;
}