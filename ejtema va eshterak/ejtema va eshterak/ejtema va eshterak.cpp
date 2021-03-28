#include <iostream>
#include <string>
#include <vector>
#define m 100
using namespace std;
int tekrar (vector <string> a,string s)
{
	int f = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == s)
			f++;
	}
	return f;
}

int main()
{
	int n;
	string b;
	cin >> n;
	int s = 0;
	vector <string> ejtema;
	vector <string> eshterak;
	int *size = new int [n];
	vector <string> members;
	for (int i = 0; i < n; i++)
	{
		cin >> size[i];
		s += size[i];
		for (int j = 0; j < size[i]; j++)
		{
			cin >> b;
			members.push_back(b);
		}
	}
	ejtema.push_back(members[0]);
	for (int i = 1; i < s; i++)
	{
		if (!tekrar (ejtema, members[i]))
			ejtema.push_back(members[i]);
	}
	for (int i = 0; i < ejtema.size(); i++)
	{
		if (tekrar (members, ejtema[i]) == n)
			eshterak.push_back(ejtema[i]);
	}
	cout << ejtema.size() << endl;
	for (int i = 0; i < ejtema.size(); i++)
		cout << ejtema[i] <<" ";
	cout << endl;
	cout << eshterak.size() << endl;
	for (int i = 0; i < eshterak.size(); i++)
		cout << eshterak[i] << " ";
	cout << endl;
	return 0;
}

