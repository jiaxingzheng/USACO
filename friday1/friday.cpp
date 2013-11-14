/*
ID: xing6231
PROG: friday
LANG: C++
*/
//
//  friday.cpp
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
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int N;
    fin>>N;
    int d[8]={0};
    int l=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<12;j++)
        {
            if(j==0||j==2||j==4||j==6||j==7||j==9||j==11)
            {

                l=l+13;
                d[l%7]++;

                l+=18;


            }
            else if(j==1)
            {
                if((1900+i)%400==0||((1900+i)%4==0&&(1900+i)%100!=0))
                {

                    l=l+13;
                    d[l%7]++;
                    l+=16;


                }
                else
                {

                    l=l+13;
                    d[l%7]++;
                    l+=15;


                }


            }
            else
            {

                l=l+13;
                d[l%7]++;

                l+=17;

            }
        }
    }
    fout<<d[6]<<" "<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<" "<<d[4]<<" "<<d[5]<<endl;


    fin.close();
    fout.close();
    return 0;
}

