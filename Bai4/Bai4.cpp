#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

vector<int> getijkt(vector<pair<int,int>> array, int x);

int main(int argc, char const *argv[])
{
    fstream fin, fout;
    fin.open("input", ios_base::in);fout.open("output", ios_base::out);
    
    vector<pair<int,int>> array;
    int n, x, temp;
    fin >> n;
    for (int i = 0; i < n; ++i){
        fin >> temp;
        pair<int,int> adder;
        adder.first = temp;
        adder.second = i;
        array.push_back(adder);
    }
    fin >> x;
        
    vector<int> result = getijkt(array, x);
    if (result.size() != 0){
        fout << result[0] << " " << result[1] << " " << result[2] << " " << result[3];
    }

    fin.close(); fout.close();
    return 0;
}

bool sortpair(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}
vector<int> getijkt(vector<pair<int,int>> array, int x){
    int n = array.size();
    vector<int> res;  
    sort(array.begin(), array.end(), sortpair);
    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j){
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                int temp = array[i].first + array[j].first + array[l].first + array[r].first;
                if (temp == x) {
                    res.push_back(array[i].second);
                    res.push_back(array[j].second);
                    res.push_back(array[l].second);
                    res.push_back(array[r].second);
                    cout << array[i].first << " " << array[j].first << " " << array[l].first << " " << array[r].first << endl;
                    break;
                }
                if (temp > x) --r;
                else ++l;
            }
		    if (res.size() != 0) {
                sort(res.begin(), res.end());
                return res;
            }
        }
    }
}


/* On2logn2
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
vector<pair<int, int>> Sum;
bool sortpair(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}
bool compare(int x, int y) {
	if (x % 10 == y / 10) return true;
	if (x % 10 == y % 10) return true;
	return false;
}
int Search(int x, int l, int r, int i) {
	if (l > r) return -1;
	int mid = (l + r) / 2;
	if (Sum[mid].first == x && !compare(i,Sum[mid].second)) return Sum[mid].second;
	if (Sum[mid].first >= x) return Search(x, l, mid - 1, i);
	return Search(x, mid + 1, r, i);
}
void main() {
	a = { 1,2,3,4,5 };
	int x; cin >> x;
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			Sum.push_back(make_pair(a[i] + a[j], i * 10 + j));
		}
	}
	sort(Sum.begin(), Sum.end(), sortpair);
	for (int i = 0; i < Sum.size(); i++) {
		cout << Sum[i].first << " " << Sum[i].second << endl;
	}
	for (int i = 0; i < Sum.size(); i++)
	{
		int temp = x - Sum[i].first;
		int s = Search(temp, 0, Sum.size() - 1, Sum[i].second);
		if (s != -1) {
			cout << Sum[i].second << " " << s;
			break;
		}
	}
}
*/