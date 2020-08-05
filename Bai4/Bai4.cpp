#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    fstream fin, fout;
    fin.open("input", ios_base::in);fout.open("output", ios_base::out);
    
    

    fin.close(); fout.close();
    return 0;
}
