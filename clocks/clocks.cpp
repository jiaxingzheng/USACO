/*
ID: xing6231
PROG: clocks
LANG: C++
*/
//
//  crypt1.cpp
//
//
//  Created by  Ö£¼ÑÐË on 13-11-19.
//  Copyright (c) 2013Äê  Ö£¼ÑÐË. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;
//#define DEBUG
int timemove[9][5]={{1,2,4,5},{1,2,3},{2,3,5,6},{1,4,7},{2,4,5,6,8},{3,6,9},{4,5,7,8},{7,8,9},{5,6,8,9}};



int main() {
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");

    int time[9];
    int j,k,l,m,n,q,w,r,t;
    int a[9][4]={0};
    int b[9][4]={0};
    int c[9][4]={0};
    int d[9][4]={0};
    int e[9][4]={0};
    int f[9][4]={0};
    int g[9][4]={0};
    int h[9][4]={0};
    int i[9][4]={0};
    int movea[9];
    int moveb[9];
    int movec[9];
    int moved[9];
    int movee[9];
    int movef[9];
    int moveg[9];
    int moveh[9];
    int movei[9];
    int result[9];
    int moveresult[30];
    int count1=0;





    for(k=0;k<9;k++)
    {
        fin>>time[k];
        if(time[k]==12)
        {
            time[k]=0;
        }
        if(time[k]==9)
        {
            time[k]=1;
        }

        if(time[k]==6)
        {
            time[k]=2;
        }



        #ifdef DEBUG
            cout<<time[k]<<endl;
        #endif // DEBUG
    }
    for(k=0;k<9;k++)
    {
            for(l=0;l<5;l++)
            {
                if(timemove[k][l]==1)
                    a[k][1]++;
                if(timemove[k][l]==2)
                    b[k][1]++;
                if(timemove[k][l]==3)
                    c[k][1]++;
                if(timemove[k][l]==4)
                    d[k][1]++;
                if(timemove[k][l]==5)
                    e[k][1]++;
                if(timemove[k][l]==6)
                    f[k][1]++;
                if(timemove[k][l]==7)
                    g[k][1]++;
                if(timemove[k][l]==8)
                    h[k][1]++;
                if(timemove[k][l]==9)
                    i[k][1]++;


            }


    }
    for(j=0;j<9;j++)
    {
        for(k=2;k<4;k++)
        {
            a[j][k]=a[j][1]*k;
            b[j][k]=b[j][1]*k;
            c[j][k]=c[j][1]*k;
            d[j][k]=d[j][1]*k;
            e[j][k]=e[j][1]*k;
            f[j][k]=f[j][1]*k;
            g[j][k]=g[j][1]*k;
            h[j][k]=h[j][1]*k;
            i[j][k]=i[j][1]*k;
        }
    }



    #ifdef DEBUG
    for(j=0;j<9;j++)
    {
        for(k=0;k<4;k++)
        {
            cout<<a[j][k]<<endl;
        }
    }
    cout<<"----------------------------------"<<endl;
    #endif

    for(j=0;j<4;j++)
    {
        for(k=0;k<4;k++)
        {
            for(l=0;l<4;l++)
            {
                for(m=0;m<4;m++)
                {
                    for(n=0;n<4;n++)
                    {
                        for(q=0;q<4;q++)
                        {
                            for(w=0;w<4;w++)
                            {
                                for(r=0;r<4;r++)
                                {
                                    for(t=0;t<4;t++)
                                    {
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==1&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            movea[0]=j;
                                            movea[1]=k;
                                            movea[2]=l;
                                            movea[3]=m;
                                            movea[4]=n;
                                            movea[5]=q;
                                            movea[6]=w;
                                            movea[7]=r;
                                            movea[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==1&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            moveb[0]=j;
                                            moveb[1]=k;
                                            moveb[2]=l;
                                            moveb[3]=m;
                                            moveb[4]=n;
                                            moveb[5]=q;
                                            moveb[6]=w;
                                            moveb[7]=r;
                                            moveb[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==1&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            movec[0]=j;
                                            movec[1]=k;
                                            movec[2]=l;
                                            movec[3]=m;
                                            movec[4]=n;
                                            movec[5]=q;
                                            movec[6]=w;
                                            movec[7]=r;
                                            movec[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==1&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            moved[0]=j;
                                            moved[1]=k;
                                            moved[2]=l;
                                            moved[3]=m;
                                            moved[4]=n;
                                            moved[5]=q;
                                            moved[6]=w;
                                            moved[7]=r;
                                            moved[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==1&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            movee[0]=j;
                                            movee[1]=k;
                                            movee[2]=l;
                                            movee[3]=m;
                                            movee[4]=n;
                                            movee[5]=q;
                                            movee[6]=w;
                                            movee[7]=r;
                                            movee[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==1&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            movef[0]=j;
                                            movef[1]=k;
                                            movef[2]=l;
                                            movef[3]=m;
                                            movef[4]=n;
                                            movef[5]=q;
                                            movef[6]=w;
                                            movef[7]=r;
                                            movef[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==1&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            moveg[0]=j;
                                            moveg[1]=k;
                                            moveg[2]=l;
                                            moveg[3]=m;
                                            moveg[4]=n;
                                            moveg[5]=q;
                                            moveg[6]=w;
                                            moveg[7]=r;
                                            moveg[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==1&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==0)
                                        {
                                            moveh[0]=j;
                                            moveh[1]=k;
                                            moveh[2]=l;
                                            moveh[3]=m;
                                            moveh[4]=n;
                                            moveh[5]=q;
                                            moveh[6]=w;
                                            moveh[7]=r;
                                            moveh[8]=t;

                                        }
                                        if((a[0][j]+a[1][k]+a[2][l]+a[3][m]+a[4][n]+a[5][q]+a[6][w]+a[7][r]+a[8][t])%4==0&&(b[0][j]+b[1][k]+b[2][l]+b[3][m]+b[4][n]+b[5][q]+b[6][w]+b[7][r]+b[8][t])%4==0&&(c[0][j]+c[1][k]+c[2][l]+c[3][m]+c[4][n]+c[5][q]+c[6][w]+c[7][r]+c[8][t])%4==0&&(d[0][j]+d[1][k]+d[2][l]+d[3][m]+d[4][n]+d[5][q]+d[6][w]+d[7][r]+d[8][t])%4==0&&(e[0][j]+e[1][k]+e[2][l]+e[3][m]+e[4][n]+e[5][q]+e[6][w]+e[7][r]+e[8][t])%4==0&&(f[0][j]+f[1][k]+f[2][l]+f[3][m]+f[4][n]+f[5][q]+f[6][w]+f[7][r]+f[8][t])%4==0&&(g[0][j]+g[1][k]+g[2][l]+g[3][m]+g[4][n]+g[5][q]+g[6][w]+g[7][r]+g[8][t])%4==0&&(h[0][j]+h[1][k]+h[2][l]+h[3][m]+h[4][n]+h[5][q]+h[6][w]+h[7][r]+h[8][t])%4==0&&(i[0][j]+i[1][k]+i[2][l]+i[3][m]+i[4][n]+i[5][q]+i[6][w]+i[7][r]+i[8][t])%4==1)
                                        {
                                            movei[0]=j;
                                            movei[1]=k;
                                            movei[2]=l;
                                            movei[3]=m;
                                            movei[4]=n;
                                            movei[5]=q;
                                            movei[6]=w;
                                            movei[7]=r;
                                            movei[8]=t;

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    #ifdef DEBUG
    for(j=0;j<9;j++)
        cout<<movea[j]<<endl;
    for(j=0;j<9;j++)
        cout<<moveb[j]<<endl;
    for(j=0;j<9;j++)
        cout<<movec[j]<<endl;
    for(j=0;j<9;j++)
        cout<<moved[j]<<endl;
    for(j=0;j<9;j++)
        cout<<movee[j]<<endl;
    for(j=0;j<9;j++)
        cout<<movef[j]<<endl;
    for(j=0;j<9;j++)
        cout<<moveg[j]<<endl;
    for(j=0;j<9;j++)
        cout<<moveh[j]<<endl;
    for(j=0;j<9;j++)
        cout<<movei[j]<<endl;


    #endif // DEBUG
    for(j=0;j<9;j++)
    {
        movea[j]=movea[j]*time[0];
        moveb[j]=moveb[j]*time[1];
        movec[j]=movec[j]*time[2];
        moved[j]=moved[j]*time[3];
        movee[j]=movee[j]*time[4];
        movef[j]=movef[j]*time[5];
        moveg[j]=moveg[j]*time[6];
        moveh[j]=moveh[j]*time[7];
        movei[j]=movei[j]*time[8];

    }
    for(j=0;j<9;j++)
    {
        result[j]=(movea[j]+moveb[j]+movec[j]+moved[j]+movef[j]+moveg[j]+movee[j]+moveh[j]+movei[j])%4;
    }
    for(j=0;j<9;j++)
    {
        if(result[j]!=0)
        {
            for(k=0;k<result[j];k++)
            {
                moveresult[count1]=j+1;
                count1++;
            }

        }

    }
    sort(moveresult,moveresult+count1);
    for(j=0;j<count1-1;j++)
    {
        fout<<moveresult[j]<<" ";
    }
    fout<<moveresult[count1-1]<<endl;


    fin.close();
    fout.close();
    return 0;

}

