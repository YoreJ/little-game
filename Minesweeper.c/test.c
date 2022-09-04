#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*****************扫雷***************\n");
	printf("************   1.play   ************\n");
	printf("************   0.exit   ************\n");
	printf("************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//布置雷信息存储
	char show[ROWS][COLS] = { 0 };//排查雷信息存储
	InitBoard(mine, ROWS, COLS,'0');//初始化布置信息
	InitBoard(show, ROWS, COLS,'*');//初始化显示信息
	/*DisplayBoard(mine, ROW, COL);*/
	DisplayBoard(show, ROW, COL);//打印棋盘
	SetMine(mine,ROW,COL);//布置雷
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);//扫雷
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			{
				printf("退出游戏\n");
				break;
			}
		default:
			{
				printf("选择错误，请重新选择！\n");
				break;
			}
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}