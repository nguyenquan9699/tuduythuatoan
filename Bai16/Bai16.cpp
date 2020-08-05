#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;

pair<int, int> largestZeroSumSubArray(vector<long long int> a) {
	int max_len = 0;
	pair<int, int> p(-1, -1);
	for (int i = 0; i < a.size(); i++) {
		int cur_sum = 0;
		for (int j = i; j < a.size(); j++) {
			cur_sum += a[j];
			if (cur_sum == 0 && (j - i + 1) > max_len) {
				max_len = j - i + 1;
				p = make_pair(i, j);
			}
		}
	}
	return p;
}
struct node {long long int S; int index;};
bool cp(node a, node b){return a.S < b.S;}
pair<int, int> largestZeroSumSubArraySort(vector<long long int> a) {
    node* b = new node[a.size()];
    node tmp;
    int s = 0, len = 0, max_len = 0, l = -1, r = -1;
    for (int i = 0; i< a.size(); i++){
        s += a[i];
        b[i] = node({s,i});
    }
    for (int i = a.size() - 1; i >= 0; i--){
        if (b[i].S == 0)
            if (i > max_len){
                max_len = i;
                l = -1; r = i;
            }
    }
    sort(b, b+a.size(), cp);
    int minIndex = b[0].index, maxIndex = b[0].index;
    long long int Snow = b[0].S;
    for (int i = 0; i < a.size(); i++){
        if (Snow == b[i].S){
            if (b[i].index > maxIndex)
                maxIndex = b[i].index;
            if (b[i].index < minIndex)
                minIndex = b[i].index;
        }
        else {
            len = maxIndex - minIndex;
            if (len > max_len){
                max_len = len;
                l = minIndex;
                r = maxIndex;
            }
            Snow = b[i].S;
            minIndex = maxIndex = b[i].index;
        }
    }
    len = maxIndex - minIndex;
    if (len > max_len){
        max_len = len;
        l = minIndex;
        r = maxIndex;
    }
    return make_pair(l+1, r);
}
pair<int, int> largestZeroSumSubArrayHash(vector<long long int> a) {
	unordered_map<long long int, int> m;
	pair<int, int> p(-1, -1);
	int sum = 0;
	int max_len = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
		if (a[i] == 0 && max_len == 0) {
			max_len = 1;
			p = make_pair(i, i);
		}
		if (sum == 0) {
			max_len = i + 1;
			p = make_pair(0, i);
		}
		if (m.find(sum) != m.end()) {
            if ((i - m[sum]) >= max_len) {
                max_len = i - m[sum];
                p = make_pair(m[sum] + 1, i);
            }
        }
        else {
            m[sum] = i;
        }
	}
	return p;
}

int main() {
	fstream fin, fout;
	fin.open("input", ios_base::in);
	fout.open("output", ios_base::out);

	int n, tmp;
	vector<long long int> a;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> tmp;
		a.push_back(tmp);
	}
	
	pair<int, int> p = largestZeroSumSubArrayHash(a);
	fout << p.first << " " << p.second;
	fin.close();
	fout.close();
	return 0;
}