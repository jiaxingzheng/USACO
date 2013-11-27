/*
ID: xing6231
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <sstream>


using namespace std;
int prime(long num)
{
    long i;
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
            return 0;
    }
    return 1;

}
long palindrome(long num)
{


    stringstream stream;
    string middle;
    stream<<num;
    middle=stream.str();
    int i;

    for(i=middle.length()-1;i>=0;i--)
    {
        middle.append(1,middle[i]);


    }
    //cout<<middle<<endl;
    stringstream stream1;
    stream1<<middle;
    stream1>>num;
    return num;
}
long palin(long num)
{

    stringstream stream;
    string middle;
    stream<<num;
    middle=stream.str();
    int i;

    for(i=middle.length()-2;i>=0;i--)
    {
        middle.append(1,middle[i]);


    }
    //cout<<middle<<endl;
    stringstream stream1;
    stream1<<middle;
    stream1>>num;
    return num;
}

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    long a,b;
    fin>>a>>b;
    //cout<<a<<" "<<b<<endl;
    //cout<<palin(123)<<endl;
    //cout<<palindrome(123)<<endl;
    long cpa=a,cpb=b;
    //cout<<cpa<<" "<<cpb<<endl;
    int i=1,j=1;
    while(cpa/10!=0)
    {

        i++;
        cpa=cpa/10;

    }
    while(cpb/10!=0)
    {
        j++;
        cpb=cpb/10;
    }
    //cout<<i<<" "<<j<<endl;
    //cout<<cpa<<" "<<cpb<<endl;
    long start,end;
    start=pow(10,i/2);
    end=pow(10,j/2+1);
    //cout<<start<<" "<<end<<endl;
    int l,k;
    for(l=a;l<12;l++)
    {
        if(l<=b&&prime(l))
            fout<<l<<endl;
    }
    if(start<10)
        start=10;
     for(k=start;k<end;k++)
    {

        long middle=palin(k);
        if(middle>=a&&middle<=b)
        {
            if(prime(middle))
                fout<<middle<<endl;
        }



    }





    fin.close();
    fout.close();
    return 0;
}
/*优化点：任意偶数长度的回文数都不可能为质数（除了11）,尾数为5必不是质数(该程序没用到)
  Executing...
   Test 1: TEST OK [0.000 secs, 3508 KB]
   Test 2: TEST OK [0.000 secs, 3508 KB]
   Test 3: TEST OK [0.043 secs, 3508 KB]
   Test 4: TEST OK [0.043 secs, 3508 KB]
   Test 5: TEST OK [0.054 secs, 3508 KB]
   Test 6: TEST OK [0.054 secs, 3508 KB]
   Test 7: TEST OK [0.540 secs, 3508 KB]
   Test 8: TEST OK [0.086 secs, 3508 KB]
   Test 9: TEST OK [0.540 secs, 3508 KB]

