// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int main()

{
	string a;
	cin >> a;
	string * aptr = &a;
	string *aptr;
	cout << *aptr;

    return 0;
}

