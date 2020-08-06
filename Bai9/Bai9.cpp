#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int a[], int l, int r, double x) {
	while (r >= l) {
		int mid = l + (r - l) / 2;
		if (a[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return r;
}

int solution(int a[], int n, int b[], int m, int s) {
	sort(a, a + n);
	int max = INT_MIN;
	for (int i = 0; i < m; i++) {
		double temp = s - b[i] - 0.5;
		int pos = binarySearch(a, 0, n - 1, temp);
		max = (b[i] + a[pos]) > max ? b[i] + a[pos] : max;
	}
	return max;
}

int main() {
	int m, n, s;
	int a[10000], b[10000];
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cout << solution(a, n, b, m, s) << endl;
	system("pause");
	return 0;
}