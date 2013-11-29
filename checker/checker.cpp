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
         for(int i=0;i<N;i++)//i表示列
        {
            if(!checker[0][i]&&!checker[1][count-i+N]&&!checker[2][count+i])//count表示行也表示已放置皇后个数-1；一行一行放置皇后。
            {
                result[count]=i+1;
                checker[0][i]=checker[1][count-i+N]=checker[2][count+i]=1;//[0][i]表示所在列，[1][count-i+N]表示所在主对角线,+N是因为避免出现负数，[2][count+i]表示副对角线。原理图:横向标记数字1,2,3.....竖向标记-1,-2,-3....中间数字为横竖向相加明显主对角线数字相等。。同理副对角线。。
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

