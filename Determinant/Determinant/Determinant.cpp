// Determinant.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
#define max  100
void setkehad(int a[max][max], int kehad[max][max], int n,int v, int k)//2 matris va satr o sotoon draye kehad ra grfte va kehad ra bdst miavarad
{	
	int u = -1;//ba satr matris kehad kar mikond
	for (int i = 0; i < n; i++)
	{
		u++;
		if (i == v)
		{
			if (v == n - 1)
				break;
			else
				i++;//ba satr matris asli kar mikond
		}
		int l = 0;//ba sotun matris kehad kar mikond
		for (int j = 0; j < n; j++)
		{
			if (j == k)
			{
				j++;//ba sotun matris asli kar mikond
				if (k == n - 1);
				else
				{
					kehad[u][l] = a[i][j];
				}
			}
			else
				kehad[u][l] = a[i][j];
			l++;
		}
		
	}
}

int det( int a[max][max], int n)
{
	int s = 0;//meqdar det
	int z = -1;//alamat det
	int kehad[max][max];
	if (n == 2)//halat paye
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else//halat haye qeir paye
	{
		for (int i = 0; i < n; i++)
		{
			setkehad(a, kehad, n,0, i);//dar satr avval jlo rfte ba kehad bdst miavarad
			z *= -1;//taqiir alamat
			s += z * a[0][i] * det(kehad, n - 1);//det
		}
		return s;
	}
}
int main()
{
	cout << "tedad satr o sotun = " << endl;
	int a;
	cin >> a;
	int arr[max][max];//matris voroodi
	int taran[max][max];//matris taranahade
	int elhaqi[max][max];//matris elhaqi
	int r_kehad[max][max];//matris rabet kehad
	float varoon[max][max];//matris makoos
	cout << "deraye ha ra vared konid" << endl;
	for (int i = 0; i < a; i++)//----------grftn matris az karbar---------------
		for (int j = 0; j < a; j++)
			cin >> arr[i][j];
	int deter = det(arr, a);//zakhire det kolli
	cout<<"det = "<<deter << endl;
	for (int i = 0; i < a; i++)//----------bdst avrdn transpose------------------
		for (int j = 0; j < a; j++)
			taran[i][j] = arr[j][i];
	int w = 1;//alamat
	for (int i = 0; i < a; i++)//----------bdst avrdn matris elhaqi---------------
		for (int j = 0; j < a; j++)
		{
			if ((i + j) % 2 == 0)w = 1;
			if ((i + j) % 2 == 1)w = -1;
			setkehad(taran, r_kehad, a, i, j);
			elhaqi[i][j] =w* det(r_kehad, a - 1);
		}
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
		{
			varoon[i][j] = elhaqi[i][j] / static_cast<float> (deter);//makoos
		}
	cout <<endl<<endl<< "varoon : " << endl;
	for (int i = 0; i < a; i++)//-------------chap matris makoos----------------------
	{
		cout << endl << endl;
		for (int j = 0; j < a; j++)
			cout <<setw(14)<< varoon[i][j] ;
	}
	cout << endl;
	return 0;//tamam
}


