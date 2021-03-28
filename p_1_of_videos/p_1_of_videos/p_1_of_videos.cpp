// p_1_of_videos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <climits>
#include <string>
using namespace std;


int main()
{
	auto a = "fdvdffg";
	cout << "enter a " << endl << a << endl << endl;
	cout << "min of short" << endl <<
		numeric_limits<short int>::min() <<
		endl;
	cout << "max of short" << endl <<
		numeric_limits<short int>::max() <<
		endl;
	cout << "min of int" << endl <<
		numeric_limits<int>::min() <<
		endl;
	cout << "max of int" << endl <<
		numeric_limits<int>::max() <<
		endl;
	cout << "min of long" << endl <<
		numeric_limits<long>::min() <<
		endl;
	cout << "max of long" << endl <<
		numeric_limits<long>::min() <<
		endl;
	cout << "min of long long" << endl <<
		numeric_limits<long long>::min() <<
		endl;
	cout << "max of long long" << endl <<
		numeric_limits<long long>::max() << endl;
	cout << "size of short :  " <<
		sizeof(short) << "  byte" << endl;
	cout << "size of long long :  " <<
		sizeof(long long) << "  byte" << endl << endl;
	string sixchar("farhad");

	cout << "string is : farhad" << endl <<
		"size of string by 6 char is : " <<
		sizeof(sixchar) << endl;
	string sentences;
	cout << "enter sentences: ";

	cout << endl << sentences << endl;
	string st = "feri";
	cout << "string : " << st << endl;
	return 0;

}

