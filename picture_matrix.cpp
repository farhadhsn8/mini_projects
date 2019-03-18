// picture_matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <cmath>
using namespace std;

 int*** createImage ( int k, int n)//k*n*3
{
 int *** arr = new  int**[k];
	for (int i = 0; i < k; ++i)
	{
		arr[i] = new  int*[n];
		for (int j = 0; j < n; ++j)
			arr[i][j] = new  int[3];
	}
	srand(time(0));
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l < 3; l++)
			{
				*(*(*(arr+ i) + j)+l)= (rand() % 256);
			}
	return arr;
}
 void display(  int k,  int n,const int***  arr) 
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "[";
			for (int l = 0; l < 3; l++)
			{
				cout << *(*(*(arr + i) + j) + l) << " ";
			}
			cout << "]";
		}
		cout << endl;
	}
}
 int*** addImage (const int*** arr1,const int*** arr2,  int k,  int n)
{
	int ***add = new int**[k];
	for (int i = 0; i < k; ++i)
	{
		add[i] = new int*[n];
		for (int j = 0; j < n; ++j)
			add[i][j] = new int[3];
	}
	for (int i=0;i<k;i++)
		for (int j= 0; j <n; j++)
			for (int l = 0; l < 3; l++)
			{
				*(*(*(add + i) + j) + l) = (*(*(*(arr1 + i) + j) + l) + *(*(*(arr2 + i) + j) + l)) / 2;
			}
	return add;
}
	int*** diffImage(const int*** arr1,const int*** arr2, int k,  int n)
	{
		int ***diff = new int**[k];
		for (int i = 0; i < k; ++i)
		{
			diff [i] = new int*[n];
			for (int j = 0; j < n; ++j)
				diff [i][j] = new int[3];
		}
		for (int i = 0; i<k; i++)
			for (int j = 0; j <n; j++)
				for (int l = 0; l < 3; l++)
				{
					fabs (*(*(*(diff + i) + j) + l) = (*(*(*(arr1 + i) + j) + l) - *(*(*(arr2 + i) + j) + l)));
				}
		return diff;
	}
	void rotateImage(const int***arr,  int k, int n)
	{
		arr = new const int**[n];
		for (int i = 0; i < n; ++i)
		{
			arr[i] = new const int*[k];
			for (int j = 0; j < k; ++j)
				arr[i][j] = new const int[3];
		}
	}

int main()
{	
	int ***q= createImage(3, 4);
    const int *p1=**q ;
	const int **p2 = &p1 ;
	const int ***p = &p2 ;
	display(3, 4, p);
	/*rotateImage(p, 3, 4);
	display(4, 3, p);*/
    return 0;
}

