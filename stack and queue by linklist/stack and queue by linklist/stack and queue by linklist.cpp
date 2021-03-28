#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
};
class queue
{
public:
	Node* head;

	queue()//constructor
	{
		head = NULL;
	}
	~queue()//distructor
	{
		cout << "QUEUE DELETED";
	}
	void enq(int x)//add to rear
	{
		Node * a = new Node();
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
	void deq()//delete from head
	{
		if (head == NULL)
			cout << "queue is empty \n";
		else
		{
			head = head->next;
		}
	}
	void printqueue()
	{
		int count = 1;
		Node * j = head;
		if (j == NULL)
			cout << "queue is empty \n";
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
class stack
{
public:
	Node * head;
	stack()
	{
		head = NULL;
	}
	~stack()
	{
		cout << "STACK DELETED";
	}
	void push(int x)
	{
		Node * a = new Node();
		a->data = x;
		a->next = head;
		head = a;
	}
	int pop()
	{
		if (head == NULL)
		{
			cout << "stack is empty";
			return 0;
		}
		int a = head->data;
		head = head->next;
		return a;
	}
	void printstack()
	{
		int count = 1;
		Node * j = head;
		if (j == NULL)
			cout << "stack is empty \n";
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
	stack s;
	s.push(34);
	s.push(56);
	s.push(17);
	s.pop();
	s.push(398);
	s.push(567);
	s.pop();
	s.push(145);
	s.printstack();
	cout << endl << endl;
	queue q;
	q.enq(24);
	q.enq(2345);
	q.enq(6786);
	q.deq();
	q.enq(47);
	q.enq(54);
	q.enq(90);
	q.enq(13);
	q.deq();
	q.deq();
	q.enq(78);
	q.enq(87);
	q.deq();
	q.printqueue();
    return 0;
}

