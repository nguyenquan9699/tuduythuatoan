#include <iostream>
#include <algorithm>

using namespace std;

int solution(int a[], int n) {
	int res = 0;
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j])
				res++;
		}
		if (a[i] == 0)
			res++;
	}
	return res;
}

int main() {
	int a[10000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << solution(a, n) << endl;
	system("pause");
	return 0;
}