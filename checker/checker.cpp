/*
ID: xing6231
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//#define DEBUG
int N,countr=0;
int checker[3][25]={0};
int result[200]={0};
ofstream fout ("checker.out");
ifstream fin ("checker.in");
void setchecker(int count)
{

    if(count==N)
    {
        //fout<<"                   "<<count<<endl;
        countr++;
        if(countr<4)
        {
            for(int i=0;i<N-1;i++)
                fout<<result[i]<<" ";
            fout<<result[N-1]<<endl;
        }


    }
    else
    {
         for(int i=0;i<N;i++)//i��ʾ��
        {
            if(!checker[0][i]&&!checker[1][count-i+N]&&!checker[2][count+i])//count��ʾ��Ҳ��ʾ�ѷ��ûʺ����-1��һ��һ�з��ûʺ�
            {
                result[count]=i+1;
                checker[0][i]=checker[1][count-i+N]=checker[2][count+i]=1;//[0][i]��ʾ�����У�[1][count-i+N]��ʾ�������Խ���,+N����Ϊ������ָ�����[2][count+i]��ʾ���Խ��ߡ�ԭ��ͼ:����������1,2,3.....������-1,-2,-3....�м�����Ϊ����������������Խ���������ȡ���ͬ���Խ��ߡ���
                setchecker(count+1);
                checker[0][i]=checker[1][count-i+N]=checker[2][count+i]=0;

            }

        }
    }
}









int main() {

    fin>>N;

    setchecker(0);
    fout<<countr<<endl;


    fin.close();
    fout.close();
    return 0;
}

