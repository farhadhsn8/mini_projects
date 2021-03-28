#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node * lchild;
	Node * rchild;
};
class btree
{
public:
	Node * root;
	btree()
	{
		root = NULL;
	}
	Node * copybt(Node * a)
	{
		if (a != NULL)
		{
			Node*b = new Node();
			b->data = a->data;
			b->lchild=copybt(a->lchild);
			b->rchild=copybt(a->rchild);
			return b;
		}
	}
	bool equal(Node * a, Node *b)
	{
		if (!a && !b)
			return 1;
		if (a->data == b->data&&equal(a->lchild, b->lchild) && equal(a->rchild, b->rchild))
			return 1;
		return 0;
	}
	int numofleaf(Node * a)
	{
		if (a == NULL)
			return 0;
		if (a->lchild == NULL&&a->rchild == NULL)
			return 1;
		else 
		{
			return numofleaf(a->lchild) + numofleaf(a->rchild);
		}
	}

	int numofnode(Node* a)
	{
		int s = 1;
		if (a == NULL)
			return 0;
		else
		{
			s += numofnode(a->lchild);
			s += numofnode(a->rchild);
			return s;
		}
	}

	int numoflevel(Node * a)
	{
		int max;
		if (a == NULL)
			return 0;
		else
		{
			int l = numoflevel(a->lchild);
			int r = numoflevel(a->rchild);
			if (l >= r)
				max = l;
			if (l <r)
				max = r;
			return 1 + max;
		}
	}
	void reversetree(Node * a)
	{
		Node * tmp = a->lchild;
		a->lchild = a->rchild;
		a->rchild = tmp;
		if (a->lchild != NULL)
			reversetree(a->lchild);
		if (a->rchild != NULL)
			reversetree(a->rchild);
	}

	void inorder_print(Node * a)
	{
		if (a)
		{
			inorder_print(a->lchild);
			cout << a->data << ",";
			inorder_print(a->rchild);
		}
	}
	void postorder_print(Node * a)
	{
		if (a)
		{
			postorder_print(a->lchild);
			postorder_print(a->rchild);
			cout << a->data << ",";
		}
	}
	void preorder_print(Node * a)
	{
		if (a)
		{
			cout << a->data << ",";
			preorder_print(a->lchild);
			preorder_print(a->rchild);
		}
	}

};
class bst
{
public:
	Node * root;
	bst()
	{
		root = NULL;
	}
	Node * search(int x,Node * a)
	{
		if (a == NULL)
			return NULL;
		if (a->data == x)
			return a;
		if (a->data > x)
			search(x, a->lchild);
		if (a->data < x)
			search(x, a->rchild);
	}
	void insert(int x, Node * a)
	{
		if (x > a->data)
		{
			if (a->rchild == NULL)
			{ 
				Node * p = new Node();
				p->data = x;
				p->lchild = p->rchild = NULL;
				a->rchild=p;
			}
			else
				insert(x, a->rchild);
		}
		if (x < a->data)
		{
			if (a->lchild == NULL)
			{
				Node * p = new Node();
				p->data = x;
				p->lchild = p->rchild = NULL;
				a->rchild = p;
			}
			else
				insert(x, a->lchild);
		}
	}

	int max(Node *a)
	{
		if (a == NULL)
			return 0;
		if (a->rchild == NULL)
			return a->data;
		else
			return max(a->rchild);
	}
	int min(Node * root)
	{
		Node* a = root;
		while (a->lchild != NULL)
			a = a->lchild;
		return a->data;
	}
};
class maxheap
{
	int a[1000] = { 0 };
	maxheap()
	{
		a[0] = 0 ;
	}

};

int main()
{

    return 0;
}

