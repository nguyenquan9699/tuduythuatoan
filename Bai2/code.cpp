#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<fstream>

using namespace std;
int countPair(vector<int> a, int n, int k) {
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
int Bai2(vector<int>a, int n, int k) {
	sort(a.begin(), a.end());
	int r = a[n-1] + a[n-2];
	int l = a[0] + a[1];
	int res = r;
	while (r >= l) {
		int mid = (r + l) / 2;
		cout << l << " " << r << endl;
		cout << "Mid: " << mid << " n: " << n << " countPair: " << countPair(a, n, mid) << endl;
		if (countPair(a, n, mid) >= k){
			r = mid - 1;
			if (mid < res){
				cout << "Update res: " << mid << endl;
				res = mid;
			}
		}
		else
			l = mid + 1;
	}
	return res;
}

int main() {
	fstream fin, fout;
    fin.open("input", ios_base::in);fout.open("output", ios_base::out);
    
    vector<pair<int,int>> array;
    int n, k, temp;
	vector<int> a;
	fin >> n >> k;
	for(int i = 0; i < n; ++i){
		fin >> temp;
		a.push_back(temp);
	}

	int res = Bai2(a, a.size(), 9);
	cout << res;
	fout << res;
	fin.close(); fout.close();
	return 0;
}
