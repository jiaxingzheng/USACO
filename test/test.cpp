/*
ID: xing6231
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    fin.close();
    fout.close();
    return 0;
}

