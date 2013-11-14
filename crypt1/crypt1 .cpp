/*
ID: xing6231
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int num[10];

    int count1=0;
    bool exist[10];
    memset(exist, 0, sizeof(exist));
    int N;
    fin>>N;
    int i;
    for(i=0;i<N;i++)
    {
        fin>>num[i];
        exist[num[i]]=true;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                for(int l=0;l<N;l++)
                {
                    for(int m=0;m<N;m++)
                    {
                        int a=num[i]*100+num[j]*10+num[k];
                        int b=num[l]*a;
                        int c=num[m]*a;
                        int d=b+c*10;
                        if(b>1000||c>1000||d>10000)
                            continue;
                        if(!exist[b%10]||!exist[c%10]||!exist[d%10])
                            continue;
                        b /= 10, c /= 10, d /= 10;
                        if(!exist[b%10]||!exist[c%10]||!exist[d%10])
                            continue;
                        d /= 10;
                        if(!exist[b / 10] || !exist[c / 10] || !exist[d % 10] || !exist[d / 10])
                            continue;
                        count1++;
                    }
                }
            }
        }
    }

    fout<<count1<<endl;
    fin.close();
    fout.close();
    return 0;
}

