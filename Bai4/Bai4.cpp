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