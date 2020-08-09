#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<int> Bai18(vector<int>a, int n, int k) {
	vector<int> s;
	s.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		s.push_back(s[i - 1] + a[i]);
	}

	int id_l = 0;
	int id_r = k - 1;
	int max = s[id_r];
	int min = s[id_l];
	int tmp = id_l;

	for (int i = 0; i < n; i++) {
		if (s[i] < min) {
			min = s[i];
			tmp = i;
		}

		if (id_r - tmp  >= k && s[i] - min > max) {
			max = s[i] - min;
			id_r = i;
			id_l = tmp + 1;
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
	int b[9] = { 3,3,0,8,4,-2,-8,-4,13};
	for (int i = 0; i < 6; i++) {
		a.push_back(b[i]);
	}

	int res = Bai18(a, 9, 4);
	cout << res;

	system("pause");

}