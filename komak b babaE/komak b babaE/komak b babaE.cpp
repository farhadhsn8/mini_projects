#include <iostream>
using namespace std;
int main()
{
	bool time[400] = { 0 };
	int n;
	int l;
	bool f = 0;
	float c, b;
	cin >> n;
	float **a = new float *[n];
	for (int i = 0; i < n; i++)
		a[i] = new float[2];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		b = a[i][0];
		b /= 0.25;
		c = a[i][1];
		c /= 0.25;
		for (int j = b; j <= c; j++)
			time[j] = 1;
	}
	for (int i = 0; i < 400; i++)
	{
		if (time[i])
			cout << i * 0.25<<" ";
		while (time[i])
		{
			i++;
			if (!time[i])
				cout << (i - 1)* 0.25<<endl;
		}
	}
	 return 0;//tamam2
}

