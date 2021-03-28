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
	unsigned long long int n;
	cin >> n;
	if (n % 2 == 0)
	{
		if (n == 6)
			cout << "2 2 2";
		else
		{
			unsigned long long int i=0;
			n = n - 2;
			for (i; i < n / 2; i++)
			{
				if (isavval((n / 2) - i) && isavval((n / 2) + i))
				{
					cout << 2 << " " << n / 2 - i << " " << n / 2 + i;
					break;
				}
			}
		}
	}
	if (n % 2 == 1)
	{
		if (isavval(n - 4))
			cout << "2 2 " << n - 4;
		else
		{
			unsigned long long int j = 3,c;
			for (j = 3; j < n; j = j + 2)
			{
				while (isavval(j))
				{
					c = n - j;
					unsigned long long int i = 0;
					for (i; i < c / 2; i++)
					{
						if (isavval(c / 2 - i) && isavval(c / 2 + i))
						{
							cout << j << " " << c / 2 - i << " " << c / 2 + i;
							break;
						}
					}
					break;
				}
				break;
			}
		}
	}
	return 0;
}//t

