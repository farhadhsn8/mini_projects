#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	string b;
	string c;
	cin >> a;
	cin >> b;
	int f = 0;
	if (a.size() < b.size())
	{
		c = a;
		a = b;
		b = c;
	}
	int j = 0;
	for (int i = 0; i < b.size(); i++)
	{
		for (j; j < a.size(); j++)
		{
			if (a[j] == b[i])
			{
				f++;
				j++;
				break;
			}
		}
	}
	if (f == b.size())
		cout << "yes";
	else
		cout << "no";


	return 0;//tamam
}
