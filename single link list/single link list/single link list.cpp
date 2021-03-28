#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
};
class linkedlist
{
public:
	Node* head;

	linkedlist()//constructor
	{
		head = NULL;
	}
	~linkedlist()//distructor
	{
	 cout << "LIST DELETED";
	}
	void addR(int x)//add to rear
	{
		Node * a=new Node();
		a->data = x;
		a->next = NULL;
		if (head == NULL)
			head = a;
		else
		{
			Node * i = head;
			while (i->next)
				i = i->next;
			i->next = a;
		}
	}
	void delH()//delete from head
	{
		if (head == NULL)
			cout << "list is empty \n";
		else
		{
			head = head->next;
		}
	}
	void printlist()
	{
		int count=1;
		Node * j = head;
		if (j == NULL)
			cout << "list is empty \n";
		else
		{
			while (j != NULL)
			{
				cout << count << ":" << j->data << endl;
				count++;
				j = j->next;
			}
		}
	}
};

int main()
{
	linkedlist s;
	s.addR(1);
	s.addR(3);
	s.addR(356);
	s.delH();
	s.addR(3);
	s.addR(38);
	s.addR(96);
	s.delH();
	s.delH();
	s.addR(3);
	s.addR(47);
	s.delH();
	s.addR(73);
	s.delH();
	s.printlist();

    return 0;
}
