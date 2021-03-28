// sudoku.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#define max 9
using namespace std;

bool changing(int eventuality[max][max][max], int sudoku[max][max])
{
	bool f = 0;
	int countzero = 0;
	int x = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)
			{
				for (int k = 0; k < 9; k++)
				{
					if (eventuality[i][j][k] == 0)
						countzero++;
					if (eventuality[i][j][k] != 0)
						x = eventuality[i][j][k];
				}
				if (countzero == 8)
				{
					sudoku[i][j] = x;
					f = 1;
				}
				x = 0;
				countzero = 0;
			}
		}
	int count = 0;
	int ii = 0;
	int jj = 0;
	for (int i = 0; i < 9; i = i + 3)
		for (int j = 0; j < 9; j = j + 3)
		{
			for (int h = 0; h < 9; h++)
			{

				int a = (i / 3) * 3;
				int b = (j / 3) * 3;
				int c = a + 3;
				int d = b + 3;
				for (int q = a; q < c; q++)
					for (int w = b; w < d; w++)
					{
						if (eventuality[q][w][h] != 0)
						{
							count++;
							ii = q;
							jj = w;
						}
					}
				if (count == 1)
				{
					sudoku[ii][jj] = h + 1;
					f = 1;
					for (int u = 0; u < 9; u++)
					{
						eventuality[ii][jj][u] = 0;
						if (u == h)
							eventuality[ii][jj][u] = h + 1;
					}
					count = 0;
					ii = 0;
					jj = 0;
				}
			}
		}
	return f;
}

void csp(int eventuality[max][max][max], int sudoku[max][max])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] != 0)
			{
				for (int z = 0; z < 9; z++)
					eventuality[i][j][z] = 0;
				eventuality[i][j][sudoku[i][j] - 1] = sudoku[i][j];
			}
			if (sudoku[i][j] == 0)
			{
				for (int k = 0; k < 9; k++)
				{
					if (sudoku[i][k] != 0)
					{
						eventuality[i][j][sudoku[i][k] - 1] = 0;
					}
				}
				for (int k = 0; k < 9; k++)
				{
					if (sudoku[k][j] != 0)
					{
						eventuality[i][j][sudoku[k][j] - 1] = 0;
					}
				}
				int a = (i / 3) * 3;
				int b = (j / 3) * 3;
				int c = a + 3;
				int d = b + 3;
				for (int q = a; q < c; q++)
					for (int w = b; w < d; w++)
					{
						if (sudoku[q][w] != 0)
							eventuality[i][j][sudoku[q][w] - 1] = 0;
					}
			}


		}
}

int main()
{
	bool change = 1;
	int eventuality[max][max][max];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				eventuality[i][j][k] = k + 1;

	int sudoku[max][max];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];
	while (change)
	{
		csp(eventuality, sudoku);
		change = changing(eventuality, sudoku);
		csp(eventuality, sudoku);
		change = changing(eventuality, sudoku);
	}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku[i][j] << " ";
			if (j == 8)
				cout << endl;
		}


	return 0;
}


