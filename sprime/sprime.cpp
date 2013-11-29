/*
ID: xing6231
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>



using namespace std;
int prime(int num)
{
    int i;
    if(num<2)
        return 0;
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
            return 0;
    }
    return 1;

}


int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    int N;
    fin>>N;
    int result[10][20];
    result[0][0]=2;
    result[0][1]=3;
    result[0][2]=5;
    result[0][3]=7;
    int count[10]={0};

    count[0]=4;



    for(int i=1;i<N;i++)
    {
        for(int k=0;k<10;k++)
        {
            for(int l=0;l<count[i-1];l++)
            {
                if(prime(result[i-1][l]*10+k))
                {
                    //cout<<result[i-1][l]<<endl;
                    result[i][count[i]]=result[i-1][l]*10+k;
                   // cout<< result[i][count[i]]<<endl<<endl;

                    count[i]++;
                }

            }

        }
    }
    sort(result[N-1],result[N-1]+count[N-1]);
    for(int j=0;j<count[N-1];j++)
    {
        fout<<result[N-1][j]<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}

