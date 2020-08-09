#include<iostream>
#include<iostream>
#include<vector>
#include<time.h>
#include <fstream>
#include<algorithm>
using namespace std;
class Point {
public:
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int DienTichDaiSo(Point a, Point b) {
		return x * (b.y - a.y) + a.x * (y - b.y) + b.x * (a.y - y);
	}
	friend ostream& operator<<(ostream& os, Point& a) {
		os << a.x << " " << a.y << endl;
		return os;
	}
};
vector<Point> _n;
vector<Point> _m;
vector<int> up;
vector<int> low;
void Input() {
	int m, n;
	ifstream input;
	input.open("output.txt");
	int x;
	int y;
	input >> n;
	for (int i = 0; i < n; i++) {
		input >> x >> y;
		_n.push_back(Point(x,y));
	}
	input >> m;
	for (int i = 0; i < m; i++) {
		input >> x >> y;
		_m.push_back(Point(x, y));
	}
	input.close();
}
bool Check(Point X, int imax, int imin) {
	if (X.x >= _n[imax].x || X.x <= _n[imin].x) {
		return false;
	}
	// xet X nam tren hay duoi
	if (_n[imin].DienTichDaiSo(_n[imax], X) < 0) {
		// X nam tren
		int l = 0, r = up.size() - 1;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (X.x > _n[up[mid]].x) l = mid;
			else r = mid;
		}
		return _n[up[l]].DienTichDaiSo(_n[up[r]], X) <= 0 ? false : true;
	}
	else if (_n[imin].DienTichDaiSo(_n[imax], X) > 0) {
		// X nam duoi
		int l = 0, r = low.size() - 1;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (X.x > _n[low[mid]].x) l = mid;
			else r = mid;
		}
		return _n[low[l]].DienTichDaiSo(_n[low[r]], X) >= 0 ? false : true;
	}
	// X nam tren imax imin thi thuoc da giac loi
	return true;
}
int main() {
	Input();

	// tm xmin, xmax
	int ixmax = 0, ixmin = 0;
	for (int i = 1; i < _n.size(); i++) {
		if (_n[ixmin].x > _n[i].x) ixmin = i;
		else if (_n[ixmax].x < _n[i].x) ixmax = i;
	}

	// xay dung danh sach cac diem nua tren
	for (int i = ixmin; i != ixmax; i = (i-1+_n.size())%_n.size()){
		up.push_back(i);
	}
	up.push_back(ixmax);
	// xay dung danh sach cac diem nua duoi
	for (int i = ixmin; i != ixmax; i = (i + 1 + _n.size()) % _n.size()) {
		low.push_back(i);
	}
	low.push_back(ixmax);
	vector<Point> res;
	for (int i = 0; i < _m.size(); i++) {
		if (Check(_m[i], ixmax, ixmin)) res.push_back(_m[i]);
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i];
	return 0;
}