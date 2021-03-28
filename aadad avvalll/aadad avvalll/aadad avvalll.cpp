#include "stdafx.h"
#include <iostream>
using namespace std;
bool isavval(unsigned long long int a)
{
	if (a == 2)
		return 1;
	if (a % 2 == 0)
		return 0;
	for (int i = 3; i < a / 2; i += 2)
	{
		if (a%i == 0)
			return 0;
	}
	return 1;
}


int main()
{
	unsigned long long int a=2;
	while (1)
	{
		if (isavval(a)) cout << a << endl;
		a++;
	}
    return 0;
}

