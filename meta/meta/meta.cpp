
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int i = 0;
	int arr[100] = { 0 };
	while (a > 0)
	{
		arr[i]=a % 2;
		a /= 2;
		i++;
	}
	a = 0;
	i--;
	for (int j = i; j >= 0; j--)
	{
		a += arr[j] * pow(2, i - j);
	}
	cout << a;

    return 0;
}

