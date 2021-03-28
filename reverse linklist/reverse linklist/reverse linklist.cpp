#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node * next;
};
class linklist
{
public:
	Node * head;
	linklist()
	{
		head = NULL;
	}
	~linklist()
	{
		cout << "deleted\n";
	}
	void add(int x)
	{
		Node *a = new Node();
		a->data = x;
		a->next = head;
		head = a;
	}
	void revese()
	{
		Node *t = head;
		Node *tmp1 = NULL;
		Node *tmp2 = NULL;
		while (t != NULL)
		{
			tmp2 = t->next; 
			t->next = tmp1; //change
			tmp1 = t;//avvali 1 gam jlo
			t = tmp2;//dovvomi 1 gam jlo
		}
		head = tmp1;
	}
	void printlist()
	{
		Node * j = head;
		if (j == NULL)
			cout << "list is empty \n";
		else
		{
			while (j != NULL)
			{
				cout << j->data << " -> ";
				j = j->next;
			}
			cout << "NULL";
		}
	}
};

int main()
{
	cout << "enter numbers ( -1 ): ";
	int a;
	linklist l;
	while (1)
	{
		cin >> a;
		if (a == -1)
			break;
		l.add(a);
	}
	l.printlist();
	cout << endl;
	l.revese();
	l.printlist();

    return 0;
}

