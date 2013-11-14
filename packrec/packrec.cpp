/*
ID: xing6231
PROG: packrec
LANG: C++
*/
//
//  packrec.cpp
//
//
//  Created by  ֣���� on 13-11-14.
//  Copyright (c) 2013��  ֣����. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>


using namespace std;
struct result{
        int right;
        int left;
}results[10000];
bool cmp(const struct result&results1,const struct result&results2)
{
    if(results1.left<results2.left)
        return true;
    return false;
}

int main() {
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    int side[4][2];
    int i,j,k,l;
    int m,n,q,w;
    int count1=0;
    struct result cpresults[10000];


    for(i=0;i<4;i++)
    {
        fin>>side[i][0]>>side[i][1];
        //cout<<leftsides[i]<<" "<<rightsides[i]<<endl;
    }


    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                for(l=0;l<2;l++)
                {
                    //��һ��ģ�ͣ��ĸ�������һ�߾����
                    if(side[0][i]==side[1][j]&&side[0][i]==side[2][k]&&side[0][i]==side[3][l])
                    {
                        results[count1].left=side[0][i];
                        results[count1].right=side[0][1-i]+side[1][1-j]+side[2][1-k]+side[3][1-l];
                        count1++;
                    }
                    //�ڶ���ģ�ͣ�����������һ�߶���ȣ���һ��֮��С�ڵ���ʣ���Ǹ�����һ��
                    if(side[0][i]==side[1][j]&&side[0][i]==side[2][k]&&side[3][l]>=side[0][1-i]+side[1][1-j]+side[2][1-k])
                    {
                        results[count1].left=side[0][i]+side[3][1-l];
                        results[count1].right=side[3][l];
                        count1++;

                    }
                    if(side[0][i]==side[3][l]&&side[0][i]==side[2][k]&&side[1][j]>=side[0][1-i]+side[2][1-k]+side[3][1-l])
                    {
                        results[count1].left=side[0][i]+side[1][1-j];
                        results[count1].right=side[1][j];
                        count1++;
                    }
                    if(side[2][k]==side[1][j]&&side[2][k]==side[3][l]&&side[0][i]>=side[1][1-j]+side[2][1-k]+side[3][1-l])
                    {
                        results[count1].left=side[2][k]+side[0][1-i];
                        results[count1].right=side[0][i];
                        count1++;
                    }
                    if(side[0][i]==side[1][j]&&side[0][i]==side[3][l]&&side[2][k]>=side[1][1-j]+side[0][1-i]+side[3][1-l])
                    {
                        results[count1].left=side[0][i]+side[2][1-k];
                        results[count1].right=side[2][k];
                        count1++;
                    }

                    for(m=0;m<4;m++)
                    {
                        for(n=0;n<4;n++)
                        {
                            if(n==m)
                                continue;
                            for(q=0;q<4;q++)
                            {
                                if(q==n||q==m)
                                    continue;
                                for(w=0;w<4;w++)
                                {
                                    if(w==n||w==m||w==q)
                                        continue;
                                    //������ģ�ͣ���������һ�߲���ȣ��ñ������������һ��֮�ʹ��ڵ��ڵ��ĸ�����һ�ߣ���һ��֮��С�ڵ��ڵ�����������һ��
                                    if(side[m][i]==side[n][j]&&side[q][k]==side[m][1-i]+side[n][1-j]&&side[w][l]==side[n][j]+side[q][1-k])
                                    {
                                        results[count1].left=side[w][l];
                                        results[count1].right=side[w][1-l]+side[q][k];
                                        count1++;

                                    }
                                    if(side[m][i]>=side[n][j]&&side[q][k]>=side[m][1-i]+side[n][1-j]&&side[w][l]<=side[m][i]+side[q][1-k])
                                    {
                                        results[count1].left=side[m][i]+side[q][1-k];
                                        results[count1].right=side[w][1-l]+side[q][k];
                                        count1++;

                                    }

                                    //���ĸ�ģ�ͣ���������һ�߲���ȣ����������β��� ��С�ڵ��ڻ���ڵ���ǰ����������һ��֮��
                                    if(side[m][i]>=side[n][j]&&side[q][k]>=side[w][l]&&side[q][k]<=side[m][1-i]+side[n][1-j])
                                    {

                                         results[count1].left=side[m][i]+side[q][1-k]+side[w][1-l];
                                        results[count1].right=side[m][1-i]+side[n][1-j];
                                        count1++;
                                    }
                                    if(side[m][i]<side[n][j]&&side[n][j]<=side[m][i]+side[w][1-l]&&side[w][l]<=side[m][1-i]&&side[q][k]>=side[w][l]&&side[q][k]<=side[m][1-i]+side[n][1-j])
                                    {

                                         results[count1].left=side[m][i]+side[q][1-k]+side[w][1-l];
                                        results[count1].right=side[m][1-i]+side[n][1-j];
                                        count1++;
                                    }


                                    //�����ģ�ͣ���������һ�߲���ȣ���һ����ӵ�������������һ�����
                                    if(side[m][i]>=side[n][j]&&side[q][k]>=side[w][l]&&side[m][1-i]+side[n][1-j]==side[q][1-k]+side[w][1-l])
                                    {
                                        results[count1].left=side[m][i]+side[q][k];
                                        results[count1].right=side[m][1-i]+side[n][1-j];
                                        count1++;

                                    }
                                    if(side[m][1-i]<=side[q][1-k]&&side[q][k]<=side[w][l]&&side[m][i]+side[q][k]==side[n][j]+side[w][l]&&side[m][1-i]+side[n][1-j]==side[q][1-k]+side[w][1-l])
                                    {
                                        results[count1].left=side[m][i]+side[q][k];
                                        results[count1].right=side[m][1-i]+side[n][1-j];
                                        count1++;

                                    }

                                }
                            }
                        }
                    }
                }
            }
        }

    }
    int middle;
    for(i=0;i<count1;i++)
    {

        if(results[i].left>results[i].right)
        {
            middle=results[i].left;
            results[i].left=results[i].right;
            results[i].right=middle;

        }

    }
    sort(results,results+count1,cmp);
    cpresults[0].left=results[0].left;
    cpresults[0].right=results[0].right;
    //cout<<cpresults[0].left<<" "<<cpresults[0].right<<endl;
    int count2=0;
    for(i=1;i<count1;i++)
    {
        //cout<<results[i].left<<" "<<results[i].right<<endl;
        if(results[i].left!=cpresults[count2].left||results[i].right!=cpresults[count2].right)
        {
            for(j=0;j<=count2;j++)
            {
                if(results[i].left==cpresults[j].left&&results[i].right==cpresults[j].right)
                    break;

            }
            if(j>count2)
            {
                count2++;

                cpresults[count2].left=results[i].left;
                cpresults[count2].right=results[i].right;

            }

        }


    }

    int area=cpresults[0].left*cpresults[0].right;
    for(i=1;i<=count2;i++)
    {
        if(area>cpresults[i].left*cpresults[i].right)
            area=cpresults[i].left*cpresults[i].right;

        //cout<<cpresults[i].left<<" "<<cpresults[i].right<<endl;

    }
    fout<<area<<endl;
    for(i=0;i<=count2;i++)
    {
        if(area==cpresults[i].left*cpresults[i].right)
            fout<<cpresults[i].left<<" "<<cpresults[i].right<<endl;

    }



    fin.close();
    fout.close();
    return 0;
}

