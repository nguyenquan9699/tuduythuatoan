#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<int> Bai18(vector<int>a, int n, int k) {
	vector<int> s;
	s.push_back(0);
	for (int i = 0; i < n; i++) {
		s.push_back(s[i] + a[i]);
	}

	int id_l = 0;
	int id_r = k - 1;
	int max = s[k];
	int min = 0;
	int tmp = id_l;

	for (int i = 1; i <= n; i++) {

		if (s[i] > max && i >= k) {
			max = s[i];
			id_r = i - 1;
			id_l = 0;
		}

		if (s[i] < min) {
			min = s[i];
			tmp = i - 1;
		}

		if (i - tmp >= k && s[i] - min > max) {
			max = s[i] - min;
			id_r = i - 1;
			id_l = tmp;
		}
	}
	vector<int> res;
	res.push_back(id_l);
	res.push_back(id_r);

	return res;
}


int main() {
	int n;
	vector<int> a;
	int b[9] = { 3,-3,5,-7,1,-7};
	for (int i = 0; i < 6; i++) {
		a.push_back(b[i]);
	}

	vector<int> res = Bai18(a, 6, 4);
	cout << res[0] << res[1];

}