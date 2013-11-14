/*
ID: xing6231
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int num[10];
    int number[1000];
    int number1[100];
    int number2[10000];
    int count1=0;
    int N;
    fin>>N;
    int i;
    for(i=0;i<N;i++)
    {
        fin>>num[i];
    }
    int m=0;
    int j,k,l;
    for( j=0;j<N;j++)
    {
        for( k=0;k<N;k++)
        {
            for( l=0;l<N;l++)
            {
                number[m]=num[j]*100+num[k]*10+num[l];
               // cout<<number[m]<<endl;
                m++;
            }
        }
    }
    int n=0;
    for(j=0;j<N;j++)
    {
        for(k=0;k<N;k++)
        {
            number1[n]=num[j]*10+num[k];
            n++;
        }
    }
    int b=0;
    for( j=0;j<N;j++)
    {
        for( k=0;k<N;k++)
        {
            for( l=0;l<N;l++)
            {
                for(i=0;i<N;i++)
                {
                    number2[b]=num[j]*1000+num[k]*100+num[l]*10+num[i];
                    //cout<<number[b]<<endl;
                    b++;
                }

            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(number[i]*(number1[j]%10)==number[k])
                {
                    for(l=0;l<m;l++)
                    {
                        if(number[i]*(number1[j]/10)==number[l])
                        {
                            for(int q=0;q<b;q++)
                            {
                                if(number[i]*number1[j]==number2[q])
                                    count1++;
                            }
                        }




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

