#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int count(vector<int> a, vector<int> b);

int main(int argc, char const *argv[])
{
    fstream fin, fout;
    fin.open("input", ios_base::in);fout.open("output", ios_base::out);
    vector<int> a, b;
    int n, m, temp;
    fin >> n;
    for(int i = 0; i < n; ++i){
        fin >> temp;
        a.push_back(temp);
    }
    fin >> m;
    for(int i = 0; i < m; ++i){
        fin >> temp;
        b.push_back(temp);
    }

    fout << count(a, b);

    fin.close(); fout.close();
    return 0;
}

int getNLess(vector<int> a, int b, int l, int r){
    if (b > a[a.size()-1])
        return a.size();
    if (b <= a[0])
        return 0;

    int mid = (l+r)/2;
    if (b > a[mid]){
        if (b <= a[mid+1]){
            return mid+1;
        }
        else {
            return getNLess(a, b, mid+1, r);
        }
    }
    else if (b <= a[mid]){
        return getNLess(a, b, l, mid-1);
    }
}

int count(vector<int> a, vector<int> b){
    int n = a.size(), m = b.size(), count = 0;

    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i)
        count += getNLess(a, b[i], 0, n-1);
    return count;
}