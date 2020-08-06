#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int a[], int l, int r, int x) {
	while (r >= l) {
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return r;
}

int solution(int a[], int n, int b[], int m) {
	sort(a, a + n);
	int min = INT_MAX;
	for (int i = 0; i < m; i++) {
		int pos = binarySearch(a, 0, n - 1, b[i]);
		int currAbs = abs(a[pos] - b[i]);
		if (pos < n - 1 && abs(a[pos + 1] - b[i]) < abs(a[pos] - b[i]))
			currAbs = abs(a[pos + 1] - b[i]);
		min = currAbs < min ? currAbs : min;
	}
	return min;
}

int main() {
	int n, m;
	int a[10000], b[10000];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cout << solution(a, n, b, m) << endl;
	system("pause");
	return 0;
}