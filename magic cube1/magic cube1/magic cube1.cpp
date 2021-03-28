// magic cube1.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n;//tedad satr o sotoon
	cout << "n = " ;
	cin >> n;
	int s = 0;//jam qotr asli
	int m = 0;//jam satr ha
	int p = 0;//jam sotoon ha
	bool f = 1;//flag
	//--------mallocation for array-------------------
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[i];
	//--------grftn array az karbar---------------------------
	for (int i = 0; i < n; i++) {
		cout << "radif " << i + 1 << " om ra vared konid" << endl;
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	//------------mohasebe jam qotr asli---------------------------
	for (int i = 0; i < n; i++)
		s += a[i][i];
		
	p = s;
	m = s;
	if (a[0][0] == a[0][1]) { cout << "invalid" << endl; f = 0; }
	//----------mohasebeye jam satr ha va sotoon ha va moqayese anha baham--------------------
	for (int i = 0; i < n; i++) {
		if (p != s) {  f = 0; }//taqiir flag
		if (m != s) {  f = 0; }//taqiir flag
		m = 0;
		p = 0;
		for (int j = 0; j < n; j++)
		{
			m += a[i][j];
			p += a[j][i];
		}
	}
	//mohasebeye jam qotr farE
	m = 0;
	for (int i = 0; i < n; i++)
		m += a[i][n-i-1];
	if (s != m) f = 0;//check qotr farE
	if (f == 1) cout << "is magic ^__^" << endl;//check flag
	if (f == 0) cout << "not magic -__-" << endl;//check flag

    return 0;
}

