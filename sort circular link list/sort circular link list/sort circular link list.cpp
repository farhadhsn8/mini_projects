#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	char data;
	Node * next;
};
class cll
{
public:
	Node * head;
	cll()
	{
		head = NULL;
	}
	void add(char x)
	{
		Node *a = new Node();
		a->data = x;
		if (head == NULL)
		{
			head = a;
		}
		if (head == head->next)
		{
			head->next= a;
		}
		else
		{
			if (head != a)
			{
				Node *i = head->next;
				while (i->next != head)
					i = i->next;
				i->next = a;
			}
		}
			a->next = head;
	}
	void print()
	{
		Node *i = head;
		if (head == head->next)
			cout << head->data;
		while (i->next != head)
		{
			cout << i->data << " -> ";
			i = i->next;
		}
		cout << endl;
	}
	void sort()
	{
		Node * i = head;
		Node * j = head;
		int tmp;
		while (i->next != head)
		{
			j = i->next;
			while (j->next != head)
			{
				if (j->data <= i->data)
				{
					tmp = j->data;
					j->data = i->data;
					i->data = tmp;
				}
				j = j->next;
			}
			i = i->next;
		}
	}
};

int main()
{
	cll list;
	char a='a';
	cout << "enter chars (-) : ";
	while (a != '-') 
	{
		cin >> a;
		list.add(a);
	}
	list.print();
	list.sort();
	cout << "sort :" << endl;
	list.print();
    return 0;
}

