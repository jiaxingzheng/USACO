/*
ID: xing6231
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>



using namespace std;
string tentoother(int c,int B)
{
    long long a[50];
    long long result=0;
    string str;
    string str1;
    char* str2;
    long long j=0;
    do
    {
        a[j]=c%B;
        c=c/B;
        j++;
    }while(c!=0);
    for(long long n=j-1;n>=0;n--)
    {
        if(a[n]==10)//str=a[n]-10+'A';
            str1='A';
        if(a[n]==11)
            str1='B';
        if(a[n]==12)
            str1='C';
        if(a[n]==13)
            str1='D';
        if(a[n]==14)
            str1='E';
        if(a[n]==15)
            str1='F';
        if(a[n]==16)
            str1='G';
        if(a[n]==17)
            str1='H';
        if(a[n]==18)
            str1='I';
        if(a[n]<10)
        {
            stringstream stream;
            stream<<a[n];
            str1=stream.str();
        }

        str+=str1;

    }

    return str;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int B;
    fin>>B;
    int a[50000];
    int c;
    for(int i=1;i<301;i++)
    {
        c=i*i;
     int a[50];
    int  result=0;
    int  j=0;
    do
    {
        a[j]=c%B;

        c=c/B;
        j++;
    }while(c!=0);
    int k;
    for(k=0;k<j;k++)
    {
        if(a[k]!=a[j-k-1])
            break;
    }
    if(k==j)
    {
        fout<<tentoother(i,B)<<" "<<tentoother(i*i,B)<<endl;




    }

    }

    fin.close();
    fout.close();
    return 0;
}

