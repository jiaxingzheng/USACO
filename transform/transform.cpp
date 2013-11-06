/*
ID: xing6231
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    string str[10];
    string str1[10];
    int N;
    fin>>N;
    int i,j;
    int result=7;
    bool flag=false;
    for(i=0;i<N;i++)
    {
        fin>>str[i];
        //cout<<str[i]<<endl;
    }
    for(i=0;i<N;i++)
    {
        fin>>str1[i];
        //cout<<str1[i]<<endl;
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[j][N-i-1]<<"90"<<endl;
            if(str[i][j]!=str1[j][N-i-1])
            {
                break;
            }
        }
        if(j<N)
            break;
    }
    if(i==N)
    {
        result=1;
        flag=true;
    }

    for(i=0;i<N;i++)
    {
        if(flag)
            break;
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[N-1-i][N-j-1]<<"180"<<endl;
            if(str[i][j]!=str1[N-1-i][N-1-j])
            {
                break;
            }
        }
        if(j<N)
            break;
    }


    if(i==N)
    {
        result=2;
        flag=true;
    }

    for(i=0;i<N;i++)
    {
        if(flag)
            break;
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[N-1-j][i]<<endl;
            if(str[i][j]!=str1[N-1-j][i])
            {
                break;
            }
        }
        if(j<N)
            break;
    }
    if(i==N)
    {
        result=3;
        flag=true;
    }

    for(i=0;i<N;i++)
    {
        if(flag)
            break;
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[i][N-1-j]<<endl;
            if(str[i][j]!=str1[i][N-1-j])
            {
                break;
            }
        }
        if(j<N)
            break;
    }

    if(i==N)
        result=4;
    for(i=0;i<N;i++)
    {
        if(flag)
            break;
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[j][i]<<endl;
            if(str[i][j]!=str1[j][i])
            {
                break;
            }
        }
        if(j<N)
            break;
    }
    if(i==N)
        result=5;
    for(i=0;i<N;i++)
    {
        if(flag)
            break;
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[N-1-i][j]<<"180"<<endl;
            if(str[i][j]!=str1[N-1-i][j])
            {
                break;
            }
        }
        if(j<N)
            break;
    }

    if(i==N)
        result=5;
    for(i=0;i<N;i++)
    {
        if(flag)
            break;
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[N-1-j][N-i-1]<<"90"<<endl;
            if(str[i][j]!=str1[N-1-j][N-i-1])
            {
                break;
            }
        }
        if(j<N)
            break;
    }
    if(i==N)
        result=5;

    for(i=0;i<N;i++)
    {
        if(flag)
            break;
        for(j=0;j<N;j++)
        {
            //cout<<str[i][j]<<" "<<str1[i][j]<<endl;
            if(str[i][j]!=str1[i][j])
            {
                break;
            }
        }
        if(j<N)
            break;
    }

    if(i==N)
        result=6;

    fout<<result<<endl;


    fin.close();
    fout.close();
    return 0;
}

