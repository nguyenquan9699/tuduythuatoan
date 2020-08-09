#include<iostream>
#include<vector>
#include<time.h>
#include <fstream>
#include<algorithm>
using namespace std;
vector<int> a;
vector<long long> prefixSum;
void generate(int n) {
	ofstream output;
	output.open("output.txt");
	srand(time(NULL));
	int flag;
	for (int i = 0; i < n; ++i) {
		flag = rand() % 2 == 0 ? 1 : -1;
		output << rand() % 1000000000 * flag << " ";
	}
	output.close();
}
void Input(int n) {
	ifstream input;
	input.open("output.txt");
	int x;
	for (int i = 0; i < n; i++) {
		input >> x;
		a.push_back(x);
	}
	input.close();
}

int sum(int i, int j) {
	return prefixSum[j + 1] - prefixSum[i];
}

int Search(int start, int end, int x) {
	if (sum(start, start) == x) return start;

	int l = start, r = end;

	while (r - l > 1) {
		int mid = (l + r) / 2;
		int s = sum(start, mid);
		if (s >= x)
		{
			r = mid;
		}
		else
			l = mid;
	}
	if (sum(start, r) == x) return r;
	return -1;
}

int main() {
	int n;
	cin >> n;
	//generate(n);
	Input(n);
	int x;
	cin >> x;

	// init prefixSum
	prefixSum.push_back(0);
	for (int i = 0; i < 2 * n; i++)
		prefixSum.push_back(prefixSum[i] + a[i % n]);

	int s = 0, e = n + 1;

	for (int i = 0; i < n; i++)
	{
		int p = Search(i, i + n, x);
		if (p != -1)
		{
			if (p - i < e - s)
			{
				s = i;
				e = p;
			}
		}

	}
	cout << s << " " << e % n << endl;
	return 0;
}