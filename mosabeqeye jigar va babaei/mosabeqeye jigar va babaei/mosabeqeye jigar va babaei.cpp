#include <iostream>
using namespace std;
int main()
{
	int n;
	bool f = 1;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i=0;i<(n+1)/2;i++)
		if (a[i] != a[n - i - 1])
		{
			f = 0;
			break;
		}
	if (f == 1)
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
	}
	else
	{
		if (a[(n / 2) - 1] > a[n - n / 2])
		{
			for (int i = 0; i <= (n + 1) / 2; i++)
				a[i] = a[n - i - 1];
		}
		else
		{

		}
	}
    return 0;
}

