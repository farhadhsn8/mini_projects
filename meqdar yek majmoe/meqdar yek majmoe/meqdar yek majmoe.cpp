#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[70];
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	cout << pow(2, n - 1)*sum<<endl;
    return 0;//tamam2
}

