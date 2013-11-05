#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>


using namespace std;


int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N;
    cin>>N;
    int start[5000];
    int endt[5000];
    int milkt[5000];
    int nomilkt[50][50];

    for(int i=0;i<N;i++)
    {
        cin>>start[i];
        cin>>endt[i];
    }
    fin.close();
    fout.close();
    return 0;
}
