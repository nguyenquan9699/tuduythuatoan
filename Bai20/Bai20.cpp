#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    fstream fin, fout;
    fin.open("input", ios_base::in);fout.open("output", ios_base::out);
    int n, m, temp;
    pair<int, int> res;
    vector<int> array;
    unordered_map<int, int> bucket; // <%m , last index>
    // input
    fin >> n;
    for(int i = 0; i < n; ++i){
        fin >> temp;
        array.push_back(temp);
    }
    fin >> m;

    for(int i = 0; i < n; ++i){
        temp = array[i] % m;
        // Chua biet cap nhat


        // m-1 100% max
        if (bucket.find(m-1) != bucket.end()){
            res.first = bucket[m-1];
            res.second = i;
        }
    }
    
    fout << res.first << " " << res.second;

    fin.close(); fout.close();
    return 0;
}
