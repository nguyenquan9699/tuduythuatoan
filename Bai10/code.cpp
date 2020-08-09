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

//Version 1
int  Bai10v1(vector<int>a, vector<int>b, int x) {
	sort(a.begin(), a.end());// nlog(n)
	sort(b.begin(), b.end());
	if (a[a.size() - 1] + b[b.size() - 1] < x || a[0] + b[0] > x)return 0;
	
	int xa = b[0] < 0 ? x - b[0] : x;
	int xb = a[0] < 0 ? x - a[0] : x;
	int rightLimit_a = BS(a, 0, a.size() - 1, xa);// chat nhi phan tim phan tu gan x nhat va nho hon or bang x ->  log(n)
	int rightLimit_b = BS(b, 0, b.size() - 1, xb);

	int leftLimit_a = 0;
	int leftLimit_b = 0;
	
	int count = 0;

	while (rightLimit_a >= leftLimit_a && rightLimit_b >= leftLimit_b) {
		if (a[rightLimit_a] + b[rightLimit_b] < x)return count;

		for (int i = leftLimit_b; i <= rightLimit_b; i++) {
			if (a[rightLimit_a] + b[i] == x) count++;
			else if (a[rightLimit_a] + b[i] < x) leftLimit_b++;
			else if (a[rightLimit_a] + b[i] > x)break; 
		}
		rightLimit_a--;

		for (int i = leftLimit_a; i <= rightLimit_a; i++) {
			if (b[rightLimit_b] + a[i] == x) count++;
			else if (b[rightLimit_b] + a[i] < x)leftLimit_a++;
			else if (b[rightLimit_b] + a[i] > x)break;
		}
		rightLimit_b--;
	}
	return count;
}
//Version 2 -- Cai tien
int  Bai10v2(vector<int>a, vector<int>b, int x) {
	sort(a.begin(), a.end());
	int count = 0;
	for (int i = 0; i < 0; i++) {
		int l = 0;
		int r = a.size()-1;
		while(l!=r) {
			int mid = (l + r) / 2;
			if (x - b[i] == a[mid]) {
				count++;
				break;
			}
			else if (x - b[i] > a[mid])l = mid+1;
			else r = mid - 1;
		}
	}

	return count;
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