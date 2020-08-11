// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[1000], d[1000], s[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		d[i] = 1;
		s[i] = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if ((a[i] < a[j]) && (d[i] < d[j] + 1))  d[i] = d[j] + 1;
	int max;
	max = 0;
	for (int i = 0; i < n; i++)
		if (d[max] < d[i]) max = i;

	for (int i = 0; i < n; i++)
		if (d[i] == 1)s[i] = 1;
		else
			for (int j = 0; j < i; j++)
				if ((a[j] > a[i]) && (d[i] == d[j] + 1)) s[i] = s[i] + s[j];

	int ketqua = 0;
	for (int i = 0; i < n; i++)
		if (d[i] == d[max]) ketqua = ketqua + s[i];

	cout << ketqua;
	system("pause");
	return 0;
}

