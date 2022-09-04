#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row ,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		if (i<row-1)
			for (j = 0; j < col; j++)
			{
				printf("---", board[i][j]);
				if (j < col - 1)
					printf("+");
			}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	printf("������Ҫ�µ�����(�� �У���");
	while (1)
	{
		scanf("%d%d", &x, &y);
		//�ж�x,xy����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã�������ѡ��");
			}
		}
		else
		{
			printf("����Ƿ�\n");
			
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("�����ߣ�\n");
	//int x = 0;
	//int y = 0;
	//printf("�����ߣ�\n");
	//while (1)
	//{
	//	x = rand() % row;
	//	y = rand() % col;
	//	if (board[x][y] == ' ')
	//	{
	//		board[x][y] = '#';
	//		break;
	//	}
	//}
	int p = 0;
	int q = 0;
	int a = 0;
	int b = 0;
	while (1)
	{
		if (p < row)
		{
			if (board[p][0] == board[p][1] && board[p][0] == '#' && board[p][2] == ' ')
			{
				board[p][2] = '#';
				break;
			}
			else if (board[p][1] == board[p][2] && board[p][1] == '#' && board[p][0] == ' ')
			{
				board[p][0] = '#';
				break;
			}
			else if (board[p][0] == board[p][2] && board[p][0] == '#' && board[p][1] == ' ')
			{
				board[p][1] = '#';
				break;
			}
			else
			{
				p++;
				continue;
			}
		}
		else if (q < col)
		{
			if (board[0][q] == board[1][q] && board[0][q] == '#' && board[2][q] == ' ')
			{
				board[2][q] = '#';
				break;
			}
			else if (board[1][q] == board[2][q] && board[1][q] == '#' && board[0][q] == ' ')
			{
				board[0][q] = '#';
				break;
			}
			else if (board[0][q] == board[2][q] && board[0][q] == '#' && board[1][q] == ' ')
			{
				board[1][q] = '#';
				break;
			}
			else
			{
				q++;
				continue;
			}
		}
		else if (board[0][0] == board[1][1] && board[0][0] == '#' && board[2][2] == ' ')
		{
			board[2][2] = '#';
			break;
		}
		else if (board[0][0] == board[2][2] && board[0][0] == '#' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		else if (board[1][1] == board[2][2] && board[1][1] == '#' && board[0][0] == ' ')
		{
			board[0][0] = '#';
			break;
		}
		else if (board[0][2] == board[1][1] && board[0][2] == '#' && board[0][2] == ' ')
		{
			board[0][2] = '#';
			break;
		}
		else if (board[0][2] == board[1][1] && board[0][2] == '#' && board[2][0] == ' ')
		{
			board[2][0] = '#';
			break;
		}
		else if (board[0][2] == board[2][0] && board[0][2] == '#' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		else if (a < row)
		{
			if (board[a][0] == board[a][1] && board[a][0] == '*' && board[a][2] == ' ')
			{
				board[a][2] = '#';
				break;
			}
			else if (board[a][1] == board[a][2] && board[a][1] == '*' && board[a][0] == ' ')
			{
				board[a][0] = '#';
				break;
			}
			else if (board[a][0] == board[a][2] && board[a][0] == '*' && board[a][1] == ' ')
			{
				board[p][1] = '#';
				break;
			}
			else
			{
				a++;
				continue;
			}
		}
		else if (b < col)
		{
			if (board[0][b] == board[1][b] && board[0][b] == '*' && board[2][b] == ' ')
			{
				board[2][b] = '#';
				break;
			}
			else if (board[1][b] == board[2][b] && board[1][b] == '*' && board[0][b] == ' ')
			{
				board[0][b] = '#';
				break;
			}
			else if (board[0][b] == board[2][b] && board[0][b] == '*' && board[1][b] == ' ')
			{
				board[1][b] = '#';
				break;
			}
			else
			{
				b++;
				continue;
			}
		}
		else if (board[0][0] == board[1][1] && board[0][0] == '*' && board[2][2] == ' ')
		{
			board[2][2] = '#';
			break;
		}
		else if (board[0][0] == board[2][2] && board[0][0] == '*' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		else if (board[1][1] == board[2][2] && board[1][1] == '*' && board[0][0] == ' ')
		{
			board[0][0] = '#';
			break;
		}
		else if (board[0][2] == board[1][1] && board[0][2] == '*' && board[0][2] == ' ')
		{
			board[0][2] = '#';
			break;
		}
		else if (board[0][2] == board[1][1] && board[0][2] == '*' && board[2][0] == ' ')
		{
			board[2][0] = '#';
			break;
		}
		else if (board[0][2] == board[2][0] && board[0][2] == '*' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		else
		{
			if (board[1][1] == ' ')
			{
				board[1][1] = '#';
				break;
			}
			else if (board[0][0] == ' ')
			{
				board[0][0] = '#';
				break;
			}
			else if (board[0][2] == ' ')
			{
				board[0][2] = '#';
				break;
			}
			else if (board[2][0] == ' ')
			{
				board[2][0] = '#';
				break;
			}
			else if (board[2][2] == ' ')
			{
				board[2][2] = '#';
				break;
			}
			else
			{
				while (1)
				{
					int x = 0;
					int y = 0;
					x = rand() % row;
					y = rand() % col;
					if (board[x][y] == ' ')
					{
						board[x][y] = '#';
						break;
					}
				}
				break;
			}

		}




	}
}

int IsFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	else
		return 'c';
}