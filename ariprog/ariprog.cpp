/*
ID: xing6231
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;
//#define Debug
struct result{
    int a;
    int b;
}results[10000];
bool cmp(const struct result& r1,const struct result& r2 )
{
    if(r1.b<r2.b)
        return true;
    else if(r1.b==r2.b)
    {
        if(r1.a<r2.a)
            return true;
    }
    return false;
}

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    int N,M;

    int count1=0;
    int countresult=0;
    fin>>N>>M;
    int i,j,k;

    bool middle[1000000];
    int S[100000];
    for(i=0;i<=M;i++)
    {
        for(j=i;j<=M;j++)
        {
            middle[i*i+j*j]=true;

        }

    }
    for(i=0;i<=M*M*2;i++)
    {
        if(middle[i]==true)
        {
            S[count1]=i;
            count1++;
        }

    }
    sort(S,S+count1);
    #ifdef Debug
    for(i=0;i<count1;i++)
    {
        fout<<S[i]<<endl;
    }
    #endif // Debug


    for(i=0;i<count1;i++)
    {

            for(k=i+1;k<count1;k++)
            {
                int l=1;

                int b=S[k]-S[i];
                if(S[i]+(N-1)*b>2*M*M)
                        break;
                while(middle[S[i]+l*b])
                {
                    l++;

                    if(l==N)
                    {
                        results[countresult].a=S[i];
                        results[countresult].b=b;
                        countresult++;
                        break;
                    }

                }

            }


    }
    sort(results,results+countresult,cmp);
    for(i=0;i<countresult;i++)
    {
        fout<<results[i].a<<" "<<results[i].b<<endl;
    }
    if(countresult==0)
        fout<<"NONE"<<endl;
    fin.close();
    fout.close();
    return 0;
}
/*Executing...
   Test 1: TEST OK [0.000 secs, 4828 KB]
   Test 2: TEST OK [0.000 secs, 4828 KB]
   Test 3: TEST OK [0.000 secs, 4828 KB]
   Test 4: TEST OK [0.000 secs, 4828 KB]
   Test 5: TEST OK [0.000 secs, 4828 KB]
   Test 6: TEST OK [0.032 secs, 4828 KB]
   Test 7: TEST OK [0.140 secs, 4828 KB]
   Test 8: TEST OK [0.292 secs, 4828 KB]
   Test 9: TEST OK [0.270 secs, 4824 KB]*/
