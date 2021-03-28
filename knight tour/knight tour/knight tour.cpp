// knight tour.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
//fill array by number that point to cost of squar
void reset_array(int a[8][8])
{

	a[0][0] = a[0][7] = a[7][0] = a[7][7] = 2;
	a[1][0] = a[0][1] = a[0][6] = a[1][7] = a[6][7] = a[7][6] = a[7][1] = a[6][0] = 3;
	a[2][0] = a[3][0] = a[4][0] = a[5][0] = a[6][1] = a[7][2] = a[7][3] = a[7][4] =
		a[7][5] = a[6][6] = a[5][7] = a[4][7] = a[3][7] = a[2][7] = a[1][6] = a[0][5] =
		a[0][5] = a[0][4] = a[0][3] = a[0][2] = a[1][1] = 4;
	a[1][2] = a[1][3] = a[1][4] = a[1][5] = a[2][1] = a[2][6] = a[3][1] = a[3][6] =
		a[4][1] = a[4][6] = a[5][1] = a[5][6] = a[6][2] = a[6][3] = a[6][4] = a[6][5] = 6;
	a[2][2] = a[2][3] = a[2][4] = a[2][5] = a[3][2] = a[3][3] = a[3][4] = a[3][5] =
		a[4][2] = a[4][3] = a[4][4] = a[4][5] = a[5][2] = a[5][3] = a[5][4] = a[5][5] = 8;

}
//----------------------------------------------------
//show 2D array
void show(int a[8][8])
{
	int i, j;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			printf("%d\t ", a[i][j]);
		}
		printf("\n\n");
	}
}
//-----------------------------------------------------------
//check around for best squar
int check_around(int a[8][8], int currentrow, int currentcolumn)
{

	int j = 0;
	int randbox[8];
	int horizontal[8];
	int vertical[8];
	horizontal[0] = 2;
	horizontal[1] = 1;
	horizontal[2] = -1;
	horizontal[3] = -2;
	horizontal[4] = -2;
	horizontal[5] = -1;
	horizontal[6] = 1;
	horizontal[7] = 2;
	vertical[0] = -1;
	vertical[1] = -2;
	vertical[2] = -2;
	vertical[3] = -1;
	vertical[4] = 1;
	vertical[5] = 2;
	vertical[6] = 2;
	vertical[7] = 1;
	int i;
	int action[8];

	for (i = 0; i<8; i++)
	{
		if (currentrow + vertical[i] >= 0
			&& currentrow + vertical[i] <= 7
			&& currentcolumn + horizontal[i] >= 0
			&& currentcolumn + horizontal[i] <= 7
			&& a[currentrow + vertical[i]][currentcolumn + horizontal[i]] != 0)
		{
			action[i] = a[currentrow + vertical[i]][currentcolumn + horizontal[i]];
		}
		else
		{
			action[i] = 9;
		}
	}

	int min = 10;
	int counter = 0;
	for (i = 0; i<8; i++)
	{
		if (min >= action[i])
		{
			min = action[i];
		}
	}
	if (min == 9)
	{
		return -1;
	}
	j = 0;
	for (i = 0; i<8; i++)
	{
		if (min == action[i])
		{
			randbox[j] = i;
			j++;
			counter++;
		}
	}

	int rnd = rand() % counter;

	return (randbox[rnd]);

}

//------------------------------------
//in this function after find best action
//by check_around action do move and fill currect squar by 0
int fill_board(int a[8][8], int b[64], int c[64], int currentrow, int currentcolumn)
{
	int p = 1;
	int k;

	a[currentrow][currentcolumn] = 0;
	b[0] = currentrow;
	c[0] = currentcolumn;
	int horizontal[8];
	int vertical[8];
	horizontal[0] = 2;
	horizontal[1] = 1;
	horizontal[2] = -1;
	horizontal[3] = -2;
	horizontal[4] = -2;
	horizontal[5] = -1;
	horizontal[6] = 1;
	horizontal[7] = 2;
	vertical[0] = -1;
	vertical[1] = -2;
	vertical[2] = -2;
	vertical[3] = -1;
	vertical[4] = 1;
	vertical[5] = 2;
	vertical[6] = 2;
	vertical[7] = 1;

	int u = 1;

	for (k = 0; k<64; k++)
	{

		if (k == 63)
		{
			return 0;
		}

		int i = check_around(a, currentrow, currentcolumn);

		if (i != -1)
		{

			currentcolumn += horizontal[i];
			currentrow += vertical[i];
			a[currentrow][currentcolumn] = 0;
			b[p] = currentrow;
			c[p] = currentcolumn;
			p++;
		}
		else
		{
			return 1;

		}

	}
	return 0;

}
//-----------------open-mind.ir----------------
//-----------------farhad-dalirani-------------
//main function .ask row and column for start
int main()
{
	system("cls");
	int i, h;
	int a[8][8];
	int b[64] = { 0 };
	int c[64] = { 0 };
	srand(time(NULL));
	reset_array(a);

	int currentrow, currentcolumn;
	printf("<Enter sqare that you want start>\n ");
	printf("0<=Number<=7\n");
	printf("Enter currentrow:");
	scanf("%d", &currentrow);
	printf("Enter currentcolumn:");
	scanf("%d", &currentcolumn);
	printf("\n\n");

	do
	{
		reset_array(a);
		h = fill_board(a, b, c, currentrow, currentcolumn);
	} while (h == 1);

	for (i = 0; i <= 63; i++)
	{
		a[b[i]][c[i]] = i;
	}
	show(a);

	return 0;
}
