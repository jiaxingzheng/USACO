/*
ID: xing6231
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int N;
    cin>>N;
    int sa=0,su=0,m=0,tu=0,w=0,th=0,f=0;
    int l=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<12;j++)
        {
            if(j==0||j==2||j==4||j==6||j==7||j==9||j==11)
            {
                l=l+13;
                if(l%7==1)
                    m++;
                if(l%7==2)
                    tu++;
                if(l%7==3)
                    w++;
                if(l%7==4)
                    th++;
                if(l%7==5)
                    f++;
                if(l%7==6)
                    sa++;
                if(l%7==0)
                    su++;
                l+=18;


            }
            else if(j==1)
            {
                if((1900+i)%400==0||((1900+i)%4==0&&(1900+i)%100!=0))
                {
                    l=l+13;
                    if(l%7==1)
                        m++;
                    if(l%7==2)
                        tu++;
                    if(l%7==3)
                        w++;
                    if(l%7==4)
                        th++;
                    if(l%7==5)
                        f++;
                    if(l%7==6)
                        sa++;
                    if(l%7==0)
                        su++;
                    l+=16;


                }
                else
                {
                    l=l+13;
                    if(l%7==1)
                        m++;
                    if(l%7==2)
                        tu++;
                    if(l%7==3)
                        w++;
                    if(l%7==4)
                        th++;
                    if(l%7==5)
                        f++;
                    if(l%7==6)
                        sa++;
                    if(l%7==0)
                        su++;
                    l+=15;


                }


            }
            else
            {
                l=l+13;
                if(l%7==1)
                    m++;
                if(l%7==2)
                    tu++;
                if(l%7==3)
                    w++;
                if(l%7==4)
                    th++;
                if(l%7==5)
                    f++;
                if(l%7==6)
                    sa++;
                if(l%7==0)
                    su++;
                l+=17;

            }
        }
    }
    cout<<sa<<" "<<su<<" "<<m<<" "<<tu<<" "<<w<<" "<<th<<" "<<f<<endl;;


    fin.close();
    fout.close();
    return 0;
}

