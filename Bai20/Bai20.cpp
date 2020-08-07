#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void printVec(vector<int> a){
    for(int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

void rotate(vector<int> &arr, int d) {
    int count = 0, m = arr.size();
    int* tempArray = new int[m];
    for(int i = 0; i<m;++i){
        tempArray[(i+d)%m] = arr[i];
    }
    for(int i = 0; i<m;++i){
        arr[i] = tempArray[i];
    }
}

int main(int argc, char const *argv[])
{
    fstream fin, fout;
    fin.open("input", ios_base::in);fout.open("output", ios_base::out);
    int n, m, temp, max = 0;
    pair<int, int> res;
    vector<int> array;
    // input
    fin >> n;
    for(int i = 0; i < n; ++i){
        fin >> temp;
        array.push_back(temp);
    }
    fin >> m;
    vector<int> lastindex;
    for(int j = m-1; j >=0; --j)
        lastindex.push_back(-1);
    
    // duyet
    for(int i = 0; i < n; ++i){
        temp = array[i] % m;
        if (temp < 0)
            temp += m;
        rotate(lastindex, temp);
        lastindex[temp] = i;
        //printVec(lastindex);
        // update max & res
        for (int j=m-1;j>=0;--j)
            if(lastindex[j] != -1){
                if(j > max){
                    max = j;
                    res.first = lastindex[j];
                    res.second = i;
                }
                break;
            }
        // quick break
        //cout << "Temp: " << temp << "\tMax: " << max << "\tRes: " << res.first << " " << res.second << endl;
        if (max == m-1)
            break;
    }

    fout << res.first << " " << res.second;

    fin.close(); fout.close();
    return 0;
}
