#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int Bai2(vector<int>a, int n, int k) {
	sort(a.begin(), a.end());

	int x;
	int sum = 0;

	for (int i = 1; i <= k; i++) {
		sum += i;
		if (sum >= k) {
			x = i;
			break;
		}
	}

	return a[x - 1 + k - sum] + a[x];	
}

int main() {
	int n;
	vector<int> a;
	int b[6] = { 3,3,0,8,-4,-2 };
	for (int i = 0; i < 6; i++) {
		a.push_back(b[i]);
	}

	int res = Bai2(a, 6, 9);
	cout << res;

	system("pause");

}