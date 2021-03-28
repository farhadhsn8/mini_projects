// stack_p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#define n 100 //max array
using namespace std;

class Stack   //tarif class
{
	private:
		char s[n];
		int  top;

	public:

		Stack()
		{       
			top = 0;
		}
		int Push(char d) //tabe push
		{
			if (isfull())
				return 0;
			else
				s[++top] = d;
			return 1;
		}
		char Pop()//tabe pop
		{
			if (isempty())
				return 0;
			else
				return s [top--];
		}
		bool isfull()//tabe is full
		{
			if (top == n) return 1;
			return 0;
		}
		bool isempty()
		{
			if (!top)return 1;
			return 0;
		}
		char peek()//balaye stack ra barmigardanad
		{
			if (isempty()) return 0;
			return s[top];
		}
		int rtop()//top ra return miknd
		{
			return top;
		}
};
bool sazgari(char now, char next)//barkhi sharayet k qalat and barresi mishavand
{
	if ((now == '(') && (next == ']')) return 0;
	if ((now == '(') && (next == '}')) return 0;
	if ((now == '[') && (next == ')')) return 0;
	if ((now == '[') && (next == '}')) return 0;
	if ((now == '{') && (next == ']')) return 0;
	if ((now == '{') && (next == ')')) return 0;
	return 1;
}

int main()
{
	char now = '0';
	char next;
	cout << "string ra vared konid = ";
	string s;
	cin >> s;
	Stack charr;
	for (int i = s.size() - 1; i >= 0; i--)//6 alamat ra vared stack miknd
	{
		if ((s[i] == '(') || (s[i] == ')') || (s[i] == '{') || (s[i] == '}') || (s[i] == '[') || (s[i] == ']'))
			charr.Push(s[i]);
	}
	int nop = 0, noa = 0, nob=0;// number of parantez     number of akolad       number of beraket
	int size0 = charr.rtop();
	bool f = 0;
	for (int i = 0; i < size0; i++)
	{
		next = charr.Pop();
		//barresi tedad baz ha va baste ha
	if (f == 1)
	{
		if ((next == ')')&&(nop==0)) { cout << "false" << endl; return 0; }
		if ((next == '}')&&(noa==0)) { cout << "false" << endl; return 0; }
		if ((next == ']')&&(nob==0)) { cout << "false" << endl; return 0; }
	}
		if (next == '(') nop++;
		if (next == ')') nop--;
		if (next == '[') nob++;
		if (next == ']') nob--;
		if (next == '{') noa++;
		if (next == '}') noa--;
		f = 1;
		if (!sazgari(now, next))
		{
			cout << "false"<<endl; return 0;
		}
		now = next;
	}
		if (nop) 
		{
			cout << "false" << endl; return 0;
		}
		if (noa) 
		{
			cout << "false"<<endl; return 0;
		}
		if (nob) 
		{
			cout << "false"<<endl; return 0;
		}
	cout << "true"<<endl;
    return 1;//tamam
}

