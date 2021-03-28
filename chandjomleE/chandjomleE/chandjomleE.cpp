// chandjomleE.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
//in tabe meqdar chandjomle E ra braye z khas hesab mikone
int meqdar(int a[], int size, int z)
{
	for (int i = 0; i < size; i++)
	{
		a[0] *= z;
		a[0] += a[i];
	}
	return a[0];
}


int main()
{	
	int l = 0;//drje chnd jomleE dovvom
	int L = 0;//drje chnd jomle E avval
	cout << " daraje chand jomleE avval" << endl;
	cin >> L;
	int ch1[10] = { 0 };//zakhire zarayeb 1
	cout << "daraje chand jomleE dovvom"<<endl;
	cin >> l;
	int ch2[10] = { 0 };//zakhire zarayeb 2
	cout<< "zarayeb chand jomleE avval  = "<< endl;//---------------------------------------
	for (int i = 9-L; i < 10; i++)
		cin >> ch1[i];
	cout << "zarayeb chand jomleE dovom  = " << endl;
	for (int i = 9-l; i <10 ; i++)
		cin >> ch2[i];
	int op = 0;//amaliat
	int z = 0;
	cout << "amaliat mored nazar ra vared konid"<<endl<<"1=zarb\n2=taqsim\n3=jam\n4=menha"<< endl;
	cin >> op;//grftn amaliat
	if (op == 1)//zarb
	{
		cout << "z =  ";
		cin >> z;
		cout << meqdar(ch1, 10, z) * meqdar (ch2 ,10,z)<<endl;
	}
	if (op == 2)//taqsim
	{
		float rishe = 0;
		rishe = (ch2[9] /static_cast <float> ( ch2[8])) * (-1.0);
		int i = 10 - L;
		for (i; i < 10; i++)
		{
			ch1[i]= (ch1[i - 1] * rishe )+ ch1[i];
		}
		for (int i = 9 - L; i < 8; i++)
			cout << "(" << static_cast <float> (ch1[i])<< "x^" << 9 - i-1 << ") + ";
		cout << ch1[8]<< endl;
		cout << "baqimande = " << ch1[9] << endl;
	}
	if (op == 3)//jaAm 
	{
		for (int i = 0; i < 10; i++)
			ch1[i] = ch2[i]+ch1[i];

		for (int i = 9 - L; i < 9; i++)
			cout << "(" << ch1[i] << "x^" << 9 - i << ") + ";
		cout << ch1[9] << endl;
		cout << "z =  ";
		cin >> z;
		cout << meqdar(ch1, 10, z)<<endl;
	}
	if (op == 4)//tfriq
	{
		for (int i = 0; i < 10; i++)
			ch2[i] *= -1;
		for (int i = 0; i < 10; i++)
			ch1[i] = ch2[i] + ch1[i];

		for (int i = 9 - L; i < 9; i++)
			cout << "(" << ch1[i] << "x^" << 9 - i << ") + ";
		cout << ch1[9] << endl;
		cout << "z =  ";
		cin >> z;
		cout << meqdar(ch1, 10, z)<<endl;
		}
    return 0;
}

