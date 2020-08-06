#include <iostream>
#include <algorithm>

using namespace std;

int countPair(int a[], int n, int k) {
	sort(a, a + n);
	int l = 0, r = n - 1, res = 0;
	while (l < r) {
		if (a[l] + a[r] <= k) {
			res += (r - l);
			l++;
		}
		else {
			r--;
		}
	}
	return res;
}

int main() {
	int a[10000];
	int n, k;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res = countPair(a, n, k);
	cout << res << endl;
	system("pause");
	return 0;
}

