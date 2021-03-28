// eight_queen_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void clearpage (int safhe[][8])
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			safhe[i][j] = 0;
}


void print(int  safhe[][8])
{
	for (int i = 0; i < 8; i++)
	{
		cout << endl;
		for (int j = 0; j < 8; j++)
			cout << safhe[i][j] << " ";
	}
}

bool kish(int safhe[][8], int x, int y)
{
	 bool k = 0;
	 for (int i = 0; i < 8; i++)
		 if (safhe[x][i] == 1) k = 1;
	 for (int i = 0; i < 8; i++)
		 if (safhe[i][y] == 1) k = 1;
	 for (int i = x, j = y;( (i <8) && (j < 8)); (i++) ,(j++))
	 {
		 if (safhe[i][j] == 1) k = 1;
	 }
	 for (int i = x, j = y; ((i < 8) && (j >= 0)); (i++) , (j--))
   	 {
		 if (safhe[i][j] == 1) k = 1;
     }
	 for (int i = x, j = y; ((i >= 0) && (j < 8)); (i--) , (j++))
	 {
		 if (safhe[i][j] == 1) k = 1;
	 }
	 for (int i = x, j = y; ((i >= 0) && (j >= 0)); (i--) , (j--))
	 {
		 if (safhe[i][j] == 1) k = 1;
	 }

	 return k;

}


bool ok(int safhe[][8], int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
	bool flag = 1;

	if (kish(safhe, 0, a1) == 1) 
		flag = 0;
	if	 (kish(safhe, 1, a2) == 1)
		flag = 0;
	if	 (kish(safhe, 2, a3) == 1)
		flag = 0;
	if	 (kish(safhe, 3, a4) == 1)
		flag = 0;
	if	(kish(safhe, 4, a5) == 1)
		flag = 0;
	if	 (kish(safhe, 5, a6) == 1) 
		flag = 0;
	if	(kish(safhe, 6, a7) == 1) 
		flag = 0;
	if	(kish(safhe, 7, a8) == 1)
		flag = 0;
	
	return flag;
		
}


int main()
{
	int safhe[8][8] = { 0 };
	print(safhe);
	int counter = 0;


	for (int i = 0; i < 8; i++)
	{	
		clearpage(safhe);
		safhe[0][i] = 1;
		for (int j = 0; j < 8; j++)
		{
			safhe[1][j] = 1;

			for (int k = 0; (k < 8)&&(k!=j) && (k != (j-1)) && (k != (j+1)); k++)
			{
				safhe[2][k] = 1;

				for (int l = 0; (l < 8) && (l != k) && (l != (k - 1)) && (l != (k + 1)); l++)
				{
					safhe[3][l] = 1;

					for (int m = 0; (m < 8) && (m != l) && (m != (l - 1)) && (m != (l + 1)); m++)
					{
						safhe[4][m] = 1;

						for (int n = 0; (n < 8) && (n != m) && (n != (m - 1)) && (n != (m + 1)); n++)
						{
							safhe[5][n] = 1;

							for (int o = 0; (o < 8) && (o != n) && (o != (n - 1)) && (o != (n + 1)); o++)
							{
								safhe[6][o] = 1;

								for (int p = 0; (p < 8) && (p != o) && (p != (o - 1)) && (p != (o + 1)); p++)
								{
									safhe[7][p] = 1;
									if (ok(safhe ,i,j,k,l,m,n,o,p) == 1) print(safhe);
									cout << counter++ << endl;

									


								}
							}
						}
					}
				}
			}
		}
	}
    return 0;
}

