// sudoku01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int sudoku[9][9];
int k = 0;

void print()
{
	for (int r = 0; r < 9; r++)
	{
		for (int s = 0; s < 9; s++)
			cout << sudoku[r][s] << " ";
		cout << endl;
	}
}

bool complete()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (sudoku[i][j] == 0)
				return false;
	return true;
}

bool promision(int k,int i ,int j,int test)
{
	for (int ii = 0; ii < 9; ii++)
	{
		if (sudoku[ii][j] == test) //check in column
			return false;
		if (sudoku[i][ii] == test)//check in row
			return false;
				
	}
	int a = i / 3 * 3;//head of box
	int b = j / 3 * 3;//head of box
	for (int ii = 0; ii < 3; ii++) // check in box
		for (int jj = 0; jj < 3; jj++)
			if (sudoku[a + ii][b + jj] == test)
				return false;
	return true;
}

bool generator(int k)
{
	
	if (complete())
	{
		print();
		return true;
	}

	for (int i = 1; i <= 9; i++)
	{
		int a = 0, b = 0, flagg = 0;
		for (int j = 0; j<9; j++)
		{
			for (int l = 0; l < 9; l++)
			{
				if (sudoku[j][l] == 0 && flagg == 0)
				{
					a = j;
					b = l;
					flagg = 1;
					//cout << a << "  " << b;
				}
			}
		}
		//sudoku[a][b] = i;
		
		if (promision(k,a,b,i))
		{
			sudoku[a][b] = i;
			if (generator(k))
				true;
			sudoku[a][b] = 0;
		}
	}
	return false;
}

void csp(int eventuality[9][9][9], int sudoku[9][9])
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


bool changing(int eventuality[9][9][9], int sudoku[9][9])
{
	bool f = 0;
	int countnzero = 0;
	int x = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)
			{
				for (int k = 0; k < 9; k++)
				{
					if (eventuality[i][j][k] != 0)
						countnzero++;
					if (eventuality[i][j][k] != 0)
						x = eventuality[i][j][k];
				}
				if (countnzero == 1)
				{
					sudoku[i][j] = x;
					f = 1;
					csp(eventuality, sudoku);
				}
				x = 0;
				countnzero = 0;
			}
		}
	int yy = 0;
	int count = 0;
	int ii = 0;
	int jj = 0;
	for (int i = 0; i < 9; i = i + 3)
		for (int j = 0; j < 9; j = j + 3)
		{
			for (int h = 0; h < 9; h++)
			{

				int a = i;
				int b = j;
				int c = a + 3;
				int d = b + 3;
				for (int q = a; q < c; q++)
					for (int w = b; w < d; w++)
						if (sudoku[q][w] == 0)
						{
							{
								if (eventuality[q][w][h] != 0)
								{
									count++;
									ii = q;
									jj = w;
									yy = eventuality[q][w][h];
								}
							}
						}

				if (count == 1)
				{
					sudoku[ii][jj] = yy;
					f = 1;
					csp(eventuality, sudoku);
					for (int u = 0; u < 9; u++)
					{
						eventuality[ii][jj][u] = 0;

					}
					eventuality[ii][jj][h] = h + 1;
				}
				count = 0;
				ii = 0;
				jj = 0;
				yy = 0;
			}
		}
	return f;
}

int main()
{
	bool change = 1;
	int eventuality[9][9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				eventuality[i][j][k] = k + 1;


	ifstream ifs;
	ifs.open("salam1.txt");
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			ifs >> sudoku[i][j];
	cout << endl << "----------------------------------*sudoku*---------------------------------------" << endl;
	print();
	cout << endl << "----------------------------------**sudoku after csp**---------------------------------------" << endl;
	while (change)
	{

		csp(eventuality, sudoku);
		change = changing(eventuality, sudoku);
		csp(eventuality, sudoku);
		change = changing(eventuality, sudoku);
	}
	print();
	cout << endl << "---------------------------------***final***----------------------------------------" << endl;
	generator(k);
	cout << endl << "-------------------------------------------------------------------------" << endl;
    return 0;
}

