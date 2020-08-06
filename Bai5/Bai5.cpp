#include <iostream>
#include <algorithm>

using namespace std;

int countSubArray(int a[], int n, int x) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] - a[i] == x)
				cnt++;
		}
		if (a[i] == x)
			cnt++;
	}
	return cnt;
}

int main() {
	int a[10000];
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << countSubArray(a, n, x) << endl;
	system("pause");
	return 0;
}