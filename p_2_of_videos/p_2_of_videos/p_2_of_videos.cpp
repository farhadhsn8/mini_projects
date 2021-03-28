// p_2_of_videos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

int main()
{
	//-----------------loop and condition----------------------------------------
	string sAge = "0";
	int nGrade = 0;
	int nTerm = 0;
	cout << "enter your age : "<<endl;
	getline(cin, sAge);
	int nAge = stoi(sAge); //string to integer
	cout << "your age is : " << nAge << endl;
	if (nAge < 5)
		cout << "to young for school \n";
	else if (nAge == 5)
		cout << "go to kindergarten \n";
	else if ((nAge > 5) && (nAge <= 17))
	{
		nGrade = nAge - 5;
		cout << "go to grade : " << nGrade << endl;
	}
	else if ((nAge >= 18) && (nAge <= 21))
	{
		cout << "go to college ^__^ " << endl;
		nTerm = nAge - 17;
		cout << "your term is : " <<
			nTerm + 1 << " or "
			<< nTerm + 2 << endl;
	}
	 //---------------diametion array-------------------------------
	int arry[2][2][2] = { {{0,1},{2,3}},{{4,5},{6,7}} };
	cout << " arry [1][0][1] is : " << arry[1][0][1]
	<< endl;
	//--------------------vector------------------------
	
	vector <int> vec1(7);
	vec1.push_back(4);
	cout << "sizeof vec1 is : "
		<< sizeof(vec1) << endl <<
		" 8 member of vector are : ";
	for (int i = 0; i < 8; i++) cout 
		<<"	"<< vec1[i]<<endl;
	//-----------------calculation------------------------

	double num1 = 0, num2 = 0;
	string calc = "";
	vector <string > calcs;
	cout << "enter calculation (ex : 5 + 3 ) : "<<endl;
	getline(cin, calc);
	stringstream aa(calc);
	string inDivStr;
	char space = ' ';

	while (getline(aa, inDivStr, space))
	{
		calcs.push_back(inDivStr);
	}
	num1 = stoi (calcs[0]);
	num2 = stoi(calcs[2]);
	string operation = calcs[1];

	if (operation == "+")
	{
		cout << num1 + num2 << endl;
	}

	if (operation == "-")
	{
		cout << num1 - num2 << endl;
	}

	if (operation == "*")
	{
		cout << num1 * num2 << endl;
	}

	if (operation == "/")
	{
		cout << num1 / num2 << endl;
	}

	return 0;
}

