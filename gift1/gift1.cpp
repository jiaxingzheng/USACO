/*
ID: xing6231
PROG: gift1
LANG: C++
*/
//
//  gift1.cpp
//
//
//  Created by  Ö£¼ÑÐË on 13-11-03.
//  Copyright (c) 2013Äê  Ö£¼ÑÐË. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	string str;
	int NP;
	fin>>NP;
	string givers[10];
	int give[10];
	int recvnum[10];
	int recv[10]={0};
	int remain[10];
	int gain[10];
	for(int i=0;i<NP;i++)
	{
		fin>>givers[i];

	}
	for(int j=0;j<NP;j++)
    {
        fin>>str;
        int k=0;
        int a,b;
        fin>>a>>b;
        while(k<NP)
        {
            if(givers[k]==str)
            {
                give[k]=a;
                recvnum[k]=b;
                if(b!=0)
                    remain[k]=a%b;
                else
                {
                    remain[k]=a;
                    give[k]=0;
                }



                for(int l=0;l<recvnum[k];l++)
                {
                    int m=0;
                    fin>>str;
                    while(m<NP)
                    {
                        if(givers[m]==str)
                        {
                            recv[m]+=give[k]/recvnum[k];


                            break;
                        }
                        m++;
                    }
                }
                break;

            }
            k++;
        }

    }
    fin.close();
    for(int n=0;n<NP;n++)
    {
        gain[n]=remain[n]+recv[n]-give[n];




        fout<<givers[n]<<" "<<gain[n]<<endl;
    }


    fout.close();
    return 0;
}

