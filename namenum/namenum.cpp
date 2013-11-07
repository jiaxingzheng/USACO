/*
ID: xing6231
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


using namespace std;

string intoint(string str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='A'||str[i]=='B'||str[i]=='C')
            str[i]='2';
        if(str[i]=='D'||str[i]=='E'||str[i]=='F')
            str[i]='3';
        if(str[i]=='G'||str[i]=='H'||str[i]=='I')
            str[i]='4';
        if(str[i]=='J'||str[i]=='K'||str[i]=='L')
            str[i]='5';
        if(str[i]=='M'||str[i]=='N'||str[i]=='O')
            str[i]='6';
        if(str[i]=='P'||str[i]=='R'||str[i]=='S')
            str[i]='7';
        if(str[i]=='T'||str[i]=='U'||str[i]=='V')
            str[i]='8';
        if(str[i]=='W'||str[i]=='X'||str[i]=='Y')
            str[i]='9';
        if(str[i]=='Z')
            str[i]='1';    //该死的dict.txt里面有包含Z的字符串
        i++;
    }

    return str;
}
int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream in("dict.txt");

    long long N;
    fin>>N;
    string str[5000];
    int i=0;
    bool flag=true;
    do
    {
        in>>str[i];
        //out<<str[i]<<" ";


        if(N==atoll(intoint(str[i]).c_str()))
        {
            fout<<str[i]<<endl;

            flag=false;
        }

        i++;
    }while(i!=5000);
    if(flag)
        fout<<"NONE"<<endl;





    fin.close();
    fout.close();
    return 0;
}

