// sortig.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void heapify (int * a,int n,int v)
{
	int max = a[v];
	if (a[2 * v + 1] > max && (2 * v + 1 )<=n-1)
		swap(a[2 * v + 1], max);
	if (a[2 * v + 2] > max && (2 * v + 2) <= n - 1)
		swap(a[2 * v + 2], max);
}

void heap_sort(int *a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
		heapify(a, n, i);
	for (int j = n - 1; j > 1; j--)
	{
		swap(a[0], a[j]);
		heapify(a, j-1, 0);
	}
}
void swap(int & a, int & b)
{
	int t=b;
	b = a;
	a = t;
}
void insertion_sort(int*a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && a[j] > a[j + 1])
		{
			swap(a[j], a[j + 1]);
			j--;
		}
	}
}
void bubble_sort(int * a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i ; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
}
void selection_sort(int * a,int n)
{
	for (int i=0; i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap (a[i], a[j]);
		}
}

int main()
{
	cout << "size of array : " << endl;
	int n = 0;
	cin >> n;
	cout << "array :" << endl;
	int * a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	heap_sort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i]<<"\t";



    return 0;
}

