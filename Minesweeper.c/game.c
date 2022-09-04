#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		if(i<10)
		{
			printf("%d ", i);
			if (i == 0)
			{
				printf("| ");
			}
		}
		else
		{
			printf("%d", i);
		}
	}
	printf("\n");
	printf("--+");
	for (i = 1; i <=col; i++)
	{
		printf("--");
	}
	printf("-");
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		if(i<10)
		{
			printf("%d | ", i);
		}
		else
		{
			printf("%d| ", i);
		}
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count= EASY_COUNT;
	while (count)
	{
		int x = rand()%row+1;
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
	}
	else
		return 0;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 1;
	int j = 1;
	int a = 1;
	int b = 1;
	int win = row*col;
	while(win>EASY_COUNT)
	{
		printf("�������Ų��׵����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')//����
			{
				printf("���ź����㱻ը���ˣ�\n��1������ף�\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//�����ף�����x��y������Χ������
			{
				int count=get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				//DisplayBoard(show, row, col);
				while (1)
				{
					i = 1;
					j = 1;
					while (i >= 1 && i <= row)
					{
						j = 1;
						while (j >= 1 && j <= col)
						{
							if (show[i][j] == '0')//��0�ҵ��˵Ļ�
							{
								show[i][j] = ' ';
								//DisplayBoard(show, row, col);
								if (show[i - 1][j - 1] == '*')//����
								{
									show[i - 1][j - 1] = get_mine_count(mine, i - 1, j - 1)+'0';
								}
								//DisplayBoard(show, row, col);
								if (show[i - 1][j] == '*')//��
								{
									show[i - 1][j] = get_mine_count(mine, i - 1, j ) + '0';
								}
								//DisplayBoard(show, row, col);
								if (show[i - 1][j + 1] == '*')//����
								{
									show[i - 1][j + 1] = get_mine_count(mine, i - 1, j + 1) + '0';
								}
								//DisplayBoard(show, row, col);
								if (show[i][j - 1] == '*')//��
								{
									show[i][j - 1] = get_mine_count(mine, i, j - 1) + '0';
								}
								//DisplayBoard(show, row, col);
								if (show[i][j + 1] == '*')//��
								{
									show[i][j + 1] = get_mine_count(mine, i , j + 1) + '0';
								}
								//DisplayBoard(show, row, col);
								if (show[i + 1][j - 1] == '*')//����
								{
									show[i + 1][j - 1] = get_mine_count(mine, i + 1, j - 1) + '0';
								}
								//DisplayBoard(show, row, col);
								if (show[i + 1][j] == '*')//��
								{
									show[i + 1][j] = get_mine_count(mine, i + 1, j ) + '0';
								}
								//DisplayBoard(show, row, col);
								if (show[i + 1][j + 1] == '*')//����
								{
									show[i + 1][j + 1] = get_mine_count(mine, i + 1, j + 1) + '0';
								}
								//DisplayBoard(show, row, col);
								break;
							}
							j++;
						}
						if (show[i][j] == ' ')
						{
							break;
						}
						i++;
					}
					if (show[i][j] == ' ')
					{
						continue;
					}
					break;
				}
				DisplayBoard(show, row, col);
			}
		}
		else
		{
			printf("��������Ƿ�����������������!");
		}
		win = 0;
		for (a = 1; a <= row; a++)
		{
			for (b = 1; b <=col; b++)
			{
				if (show[a][b] == '*')
				{
					win++;
				}
			}
		}


	}
	if (win== EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n��1������ף�\n");
		DisplayBoard(mine, row, col);
	}
}