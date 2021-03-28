#include <iostream>
using namespace std;
long long int f(int n, int k)
{
	if (n == 0 && k == 0)
		return 1;
	if (n == 0 || k == 0)
		return 0;
	return k*f(n - 1, k) + f(n - 1, k - 1);
}
int main()
{
	while (1)
	{
		int n, k;
		cin >> n >> k;
		cout << f(n, k) % 1000000001;
	}
	return 0;
}

