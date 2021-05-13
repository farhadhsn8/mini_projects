// 98.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int maxim(int p[], int n, int s, int n1)
{
	int m = p[s];
	for (int i = s; i<n1 - 1; i++)
	{

		if (p[i + 1]>m)
			m = p[i + 1];
	}
	return m;
}
int minim(int p[], int n, int s, int n1)
{
	int m = p[s];
	for (int i = s; i<n1 - 1; i++)
	{

		if (p[i + 1]<m)
			m = p[i + 1];
	}
	return m;
}
int main()
{
	int n = 0;
	int k = 0;
	int f;
	cin >> n >> k;
	int *p = new int[n];
	for (int i = 0; i<n; i++)
		cin >> p[i];
	if (k == 1)
		f = maxim(p, n, 0, n);
	if (k == 2)
	{
		int a = 0;
		int b = 0;
		int c = 0;
		f = p[0];
		for (int j = 1; j<n; j++)
		{
			a = maxim(p, n, 0, j );
			b = maxim(p, n, j, n);
			if (a<f)
				f = a;
			if (b<f)
				f = b;
		}

	}
	if (k>2)
	{
		f = minim(p, n, 0, n);
	}
	cout << f;

	return 0;
}//qqq

