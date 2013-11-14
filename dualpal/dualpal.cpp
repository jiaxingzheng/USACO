/*
ID: xing6231
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<algorithm>



using namespace std;

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N,S;
    fin>>N>>S;
    long a[50000];
    int c;
    int count=0;
    int result[100];
    for(int i=S+1;;i++)
    {
        int countB=0;
        for(int B=2;B<=10;B++)
        {
            c=i;
            int a[50];
            long  j=0;
            do
            {
                a[j]=c%B;

                c=c/B;
                j++;
            }while(c!=0);
            int k;
            for(k=0;k<j;k++)
            {
                if(a[k]!=a[j-k-1]||a[0]==0||a[j-1]==0)
                break;
            }
            if(k==j)
                countB++;
            if(countB==2)
            {
                result[count]=i;
                count++;
                break;
            }


        }
        if(count==N)
            break;


    }
    sort(result,result+N);
    for(int m=0;m<N;m++)
    {
        fout<<result[m]<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}

