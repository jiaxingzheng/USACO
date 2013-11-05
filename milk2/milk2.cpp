/*
ID: xing6231
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>


using namespace std;


bool cmp(int p,int q){
    return p>q;
}
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
    for(int j=0;j<N;j++)
    {
        for(int k=0;k<N;k++)
        {
            if(start[j]<=start[k]&&endt[k]>=endt[j]&&start[k]<=endt[j])
            {
                milkt[j]=endt[k]-start[j];
            }
        }
        for(int m=0;m<N;m++)
        {
            int n;
            for(n=0;n<N;n++)
            {
                if(start[j]>start[n]&&endt[m]<=start[n]&&n!=m&n!=j)
                    break;
            }
            if(n=N)
                nomilkt[j][m]=start[j]-endt[m];

        }
    }
    sort(milkt,milkt+N);
    sort((int*)nomilkt,(int*)nomilkt+N*N,cmp);
    cout<<nomilkt[0]<<endl;
    cout<<milkt[N-1]<<endl;


    fin.close();
    fout.close();
    return 0;
}

