#include <iostream>
using namespace std;
bool avval(int a)
{
	if (a == 2)
		return 1;
	if ( a % 2 == 0)
		return 0;
	for (int i = 3; i < a / 2; i+=2)
	{
		if (a%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int n, j;
	cin >> n;
	int m = n;
	for (int i = 2; i <= n / 2; i++)
	{
		j = 0;
		while ((avval(i)) && (m%i == 0))
		{
			j++;
			if (j == 1)
				cout << i;
			m /= i;
		}
		if (j)
			cout << " " << j << endl;
	}
    return 0;
}

