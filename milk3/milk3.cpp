/*
ID: xing6231
PROG: milk3
LANG: C++
*/
//
//  milk3.cpp
//
//
//  Created by  Ö£¼ÑÐË on 13-11-21.
//  Copyright (c) 2013Äê  Ö£¼ÑÐË. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct milk{
    int init=0;
    int now=0;
}m[3];

int exist[21][21][21]={0};

void pour(struct milk& m1,struct milk& m2)
{
    if(m1.now>=m2.init-m2.now)
    {
        m1.now=m1.now-(m2.init-m2.now);
        m2.now=m2.init;
    }
    else
    {
        m2.now=m2.now+m1.now;
        m1.now=0;

    }

}
int result[21]={0};
void possibility(int a,int b,int c)
{
    m[0].now=a;
    m[1].now=b;
    m[2].now=c;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                continue;
            pour(m[i],m[j]);
            if(!exist[m[0].now][m[1].now][m[2].now])
            {
                exist[m[0].now][m[1].now][m[2].now]=1;
                if(m[0].now==0)
                    result[m[2].now]=1;
                possibility(m[0].now,m[1].now,m[2].now);
            }
            m[0].now=a;
            m[1].now=b;
            m[2].now=c;
        }
    }
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    fin>>m[0].init>>m[1].init>>m[2].init;
    m[2].now=m[2].init;
    possibility(m[0].now,m[1].now,m[2].now);


    for(int i=0;i<m[2].init;i++)
    {
        if(result[i]==1)
            fout<<i<<" ";
    }
    fout<<m[2].init<<endl;









    fin.close();
    fout.close();
    return 0;
}

