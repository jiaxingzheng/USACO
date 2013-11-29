/*
ID: xing6231
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//#define DEBUG
int N,count0,countr=0;
int checker[13][13]={0};
int result[100]={0};
ofstream fout ("checker.out");
ifstream fin ("checker.in");
void setchecker(int count)
{

    if(count==N)
    {
        //fout<<"                   "<<count<<endl;
        countr++;
        if(countr<4)
        {
            for(int i=0;i<N-1;i++)
                fout<<result[i]<<" ";
            fout<<result[N-1]<<endl;
        }


    }
    else
    {
         for(int i=0;i<N;i++)
        {

            for(int j=0;j<N;j++)
            {

                if(checker[i][j]==0)
                {
                    result[count]=j+1;
                    int middle[13][13];
                    for(int q=0;q<N;q++)
                    {
                        for(int w=0;w<N;w++)
                        {
                            middle[q][w]=checker[q][w];
                        }
                    }

                    for(int k=0;k<N;k++)
                    {
                        checker[i][k]=1;
                        checker[k][j]=1;
                        if(k!=0&&i-k>=0&&j-k>=0)
                            checker[i-k][j-k]=1;
                        if(k!=0&&i-k>=0&&j+k<N)
                            checker[i-k][j+k]=1;
                        if(k!=0&&i+k<N&&j-k>=0)
                            checker[i+k][j-k]=1;
                        if(k!=0&&i+k<N&&j+k<N)
                            checker[i+k][j+k]=1;
                    }

                    #ifdef DEBUG
                    for(int a=0;a<N;a++)
                    {
                        for(int b=0;b<N;b++)
                        {
                            fout<<checker[a][b]<<" ";
                            if(b==N-1)
                                fout<<endl;
                        }
                    }
                    fout<<"i:"<<i<<" "<<"j"<<j<<endl;
                    #endif // DEBUG

                    #ifdef DEBUG
                    fout<<"count:"<<count<<endl;
                    #endif // DEBUG


                    setchecker(count+1);
                    for(int q=0;q<N;q++)
                    {
                        for(int w=0;w<N;w++)
                        {
                            checker[q][w]=middle[q][w];
                        }
                    }
                    checker[i][j]=1;

                }
            }
        }
    }
}









int main() {

    fin>>N;

    setchecker(0);
    fout<<countr<<endl;


    fin.close();
    fout.close();
    return 0;
}

