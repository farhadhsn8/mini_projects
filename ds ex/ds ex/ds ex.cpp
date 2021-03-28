// ds ex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class stack
{
public :
	int arr[1000];
	int top;
private:
	bool isempty()
	{
		if (!top)
			return 1;
		else
			return 0;
	}
	bool isfull()
	{
		if (top == 999)
			return 1;
		return 0;
	}
	void push(int a)
	{
		if (!isfull())
		{
			arr[++top] = a;
		}
		else
			cout << "is full " << endl;
	}
	int pop()
	{
		if (!isempty())
			return arr[top--];
		else
			return 0;
	}
};
int main()
{
	stack u;
	int nop = 0, nob = 0, noa = 0;
	bool natije = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (u.isempty())

	}



	return 0;
}

