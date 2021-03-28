// jaigasht.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void permutation(int head, int tail[], int n)
{
	if (n == 1)
	{
		cout << head << " " << tail[n] << endl << tail[n] << " " << head;
	}
	if (n > 1)
	{
		cout << head << " ";
		permutation(tail[n - 1], tail, n);
		cout << endl;
		permutation(tail[n - 1], tail, n);
		cout << head << " ";
	}
}
int main()
{
	int a;
	cin >> a;
	int * arr = new int[a];
	for (int i = 0; i < a; i++)
	{
		cin >> arr[i];
	}
	permutation(arr[a], arr, a - 1);
    return 0;
}

