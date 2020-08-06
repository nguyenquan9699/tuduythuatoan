#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int **a, int n, int m) {
	int max = a[0][0];
	for (int i = 1; i < n; i++)
		a[i][0] += a[i - 1][0];
	for (int i = 1; i < m; i++)
		a[0][i] += a[0][i - 1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	}

	for (int l = 0; l < n; l++) {
		for (int t = 0; t < m; t++) {
			for (int r = l; r < n; r++) {
				for (int b = t; b < m; b++) {
					int lArea = t > 0 ? a[r][t - 1] : 0;
					int tArea = l > 0 ? a[l - 1][b] : 0;
					int ltArea = 0;
					if (l > 0 && t > 0)
						ltArea = a[l - 1][t - 1];
					int currArea = a[r][b] - lArea - tArea + ltArea;
					max = currArea > max ? currArea : max;
				}
			}
		}
	}
	return max;
}

int main() {
	int **a;
	int n, m;
	cin >> n >> m;
	a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cout << solution(a, n, m) << endl;
	system("pause");
	return 0;
}