#include<iostream>
#include<vector>
#include<time.h>
#include <fstream>
#include<algorithm>
using namespace std;
vector<int> a;
vector<int> b;
void generate(int n, int m) {
	ofstream output;
	output.open("output.txt");
	srand(time(NULL));
	int flag;
	for (int i = 0; i < n; ++i) {
		flag = rand() % 2 == 0 ? 1 : -1;
		output << rand() % 1000000000 * flag << " ";
	}
	output << endl;
	for (int i = 0; i < m; ++i) {
		flag = rand() % 2 == 0 ? 1 : -1;
		output << rand() % 1000000000 * flag << " ";
	}
	output.close();
}
void Input(int n, int m) {
	ifstream input;
	input.open("output.txt");
	int x;
	for (int i = 0; i < n; i++) {
		input >> x;
		a.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		input >> x;
		b.push_back(x);
	}
	input.close();
}

int main() {
	int n, m;
	cin >> n >> m;
	//generate(n, m);
	Input(n, m);
	int res1 = 0, res2 = 0;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	// code

	return 0;
}