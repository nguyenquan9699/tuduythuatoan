#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
int BS(vector<int>a,int l,int r,int x) {

	int mid = (l + r) / 2;
	if (x == a[mid] || l == r) return mid;
	else if (x > a[mid])return BS(a, mid+1, r, x);
	else return BS(a, l, mid-1, x);
}

int Bai14(vector<int>a, vector<int> b,int n, int m) {
	sort(a.begin(), a.end());
	
	int min = 0;
	for (int i = 0; i < m; i++) {
		int x = BS(a, 0, n - 1, - b[i]);
		int sum = abs(b[i] + a[x]);
		if (x < n - 1 && sum > abs(b[i] + a[x + 1])) sum = abs(b[i] + a[x + 1]);

		if (sum < min) min = sum;
	}

	return min;
 }



int main() {
	int n;
	vector<int> a;
	int b[6] = { 3,3,0,8,-4,-2 };
	for (int i = 0; i < 6; i++) {
		a.push_back(b[i]);
	}

	int res;
	cout << res;

	system("pause");

}