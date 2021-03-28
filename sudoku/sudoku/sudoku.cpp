// sudoku.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <thread>
#define max 9
using namespace std;

bool trow = 0;//chon thread meqdar return nmikone
bool tcolumn = 0;
bool tbox = 0;

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
						if (sudoku [q][w] != 0)
							eventuality[i][j][sudoku[q][w] - 1] = 0;
					}
			}
			

		}
}


void is_in_row(int grid[max][max], int row, int num)
{
	for (int col = 0; col < max; col++)
		if (grid[row][col] == num)
		{
			trow = 1;
			return;
		}
	trow = 0;
	return;
}

void is_in_column(int grid[max][max], int col, int num)
{
	for (int row = 0; row < max; row++)
		if (grid[row][col] == num)
		{
			tcolumn = 1;
			return;
		}
	tcolumn=0;
	return;
}
void is_in_box(int grid[max][max], int boxStartRow,
	int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow][col + boxStartCol] == num)
			{
				tbox = 1;
				return;
			}
	tbox = 0;
	return;
}



bool isSafe(int grid[max][max], int row,int col, int num)
{
	thread thread1( is_in_row,grid, row, num);
	thread thread2(is_in_column,grid, col, num);
	thread thread3(is_in_box,grid, row - row % 3,col - col % 3, num);
	thread1.join();
	thread2.join();
	thread3.join();
	return !trow &&!tcolumn &&!tbox&&grid[row][col] == 0;
}

bool find_empty_box(int grid[max][max],int &row, int &col)
{
	for (row = 0; row < max; row++)
		for (col = 0; col < max; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

bool SolveSudoku(int grid[max][max])
{
	int row, col;
	if (!find_empty_box(grid, row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (isSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (SolveSudoku(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}
void printsudoku(int grid[max][max])
{
	for (int row = 0; row < max; row++)
	{
		for (int col = 0; col < max; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
}

bool changing(int eventuality[max][max][max], int sudoku[max][max])
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
							eventuality[ii][jj][h] = h+1;
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
	int eventuality[max][max][max];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				eventuality[i][j][k] = k + 1;
	ifstream ifs;
	ifs.open("salam.txt");

	int sudoku[max][max];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			ifs >> sudoku[i][j];

	cout << endl << "-------------------------------------------------------------------------" << endl;
	while (change)
	{

		csp(eventuality, sudoku);
		change = changing(eventuality, sudoku);
		csp(eventuality, sudoku);
		change = changing(eventuality, sudoku);
	}
	
	csp(eventuality, sudoku);
	changing(eventuality, sudoku);
	//if (SolveSudoku(sudoku) == true)
		printsudoku(sudoku);
	//else
	//	cout << "No solution exists"<<endl;

	cout << "-------------------------------------------"<<endl;

    return 0;
}

