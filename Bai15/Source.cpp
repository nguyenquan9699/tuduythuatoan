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

int main() {
	int n;
	cin >> n;
	//generate(n);
	Input(n);
	

	// init prefixSum
	prefixSum.push_back(0);
	for (int i = 0; i < n; i++)
		prefixSum.push_back(prefixSum[i] + a[i]);
	

	// O(n^2)
	long long sum_max = prefixSum[1];
	int x = 0, y = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long temp = prefixSum[j] - prefixSum[i];
			if (sum_max < temp) {
				sum_max = temp;
				x = i;
				y = j;
			}
		}
	}
	y = (y - 1) >= 0 ? y - 1 : x;
	cout << sum_max << endl << x << endl << y;
	
	return 0;
}