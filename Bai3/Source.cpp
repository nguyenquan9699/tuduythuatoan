#include<iostream>
#include<vector>
#include<time.h>
#include <fstream>
#include<algorithm>
using namespace std;
vector<pair<int,int>> a;
void generate(int n) {
	ofstream output;
	output.open("output.txt");
	srand(time(NULL));
	int flag;
	for (int i = 0; i < n; ++i){
		flag = rand() % 2 == 0 ? 1 : -1;
		output << rand() % 1000000000 * flag << " ";
	}
	output.close();
}
void Input(int n) {
	ifstream input;
	input.open("output.txt");
	int x;
	for (int i = 0; i < n; i++){
		input >> x;
		a.push_back(make_pair(x,i));
	}
	input.close();
}
bool sortpair(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}
int main() {
	int n;
	cin >> n;
	generate(n);
	Input(n);
	vector<int> res;

	int x;
	cin >> x;
	sort(a.begin(), a.end(), sortpair);
	// code
	for (int i = 0; i < n; i++)
	{
		int l = i + 1, r = n - 1;
		while (l < r)
		{
			int temp = a[i].first + a[l].first + a[r].first;
			if (temp == x) {
				res.push_back(a[i].second);
				res.push_back(a[l].second);
				res.push_back(a[r].second);
				cout << a[i].first << " " << a[l].first << " " << a[r].first << endl;
				break;
			}
			if (temp > x) --r;
			else ++l;

		}
		if (res.size() != 0) break;
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}