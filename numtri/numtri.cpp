/*
ID: xing6231
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int num[1000][1000];
    int R;
    fin>>R;
    int result[1000][1000];
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<=i;j++)
        {
            fin>>num[i][j];
            if(i==R-1)
                result[i][j]=num[i][j];
            //cout<<num[i][j];
        }
    }
    for(int k=R-2;k>=0;k--)
    {
        for(int l=0;l<=k;l++)
        {
            result[k][l]=max(result[k+1][l+1],result[k+1][l])+num[k][l];
            //cout<<result[k][l]<<endl;
        }
    }
    fout<<result[0][0]<<endl;


    fin.close();
    fout.close();
    return 0;
}

