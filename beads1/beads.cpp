/*
ID: xing6231
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;
int getMaximum(int N,string str)
{
    int l=1;
    int r=1;
    int rb[350]={0};
    int br[350]={0};
    for(int i=0;i<N;i++)
    {

        while((str[i-l]=='r'&&i-l>=0)||(str[i-l]=='w'&&i-l>=0))
        {
            l++;


        }
        while(str[i+r]=='b'||str[i+r]=='w')
        {
            r++;

        }

        rb[i]=l+r-1;
        if(rb[i]>N)
            rb[i]=N;

        l=1;
        r=1;
        while((str[i-l]=='b'&&i-l>=0)||(str[i-l]=='w'&&i-l>=0))
        {
            l++;

        }
        while(str[i+r]=='r'||str[i+r]=='w')
        {
            r++;

        }

        br[i]=l+r-1;
        if(br[i]>N)
            br[i]=N;
        l=1;
        r=1;


    }


    sort(rb,rb+N);
    sort(br,br+N);
    if(rb[N-1]>br[N-1])
        return rb[N-1];
    else
        return br[N-1];
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	int N;
	fin>>N;
	string str;
	fin>>str;
	str+=str;
	fout<<getMaximum(N,str)<<endl;




    fin.close();
    fout.close();
    return 0;
}

