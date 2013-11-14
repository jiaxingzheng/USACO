/*
ID: xing6231
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>


using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M,S,C;

    fin>>M>>S>>C;
    int cow[201];
    int space[201];
    int copyspace[201];
    int index[200];
    int result[200];
    int totalnumber=0;

    for(int i=0;i<C;i++)
    {
        fin>>cow[i];
    }
    sort(cow,cow+C);
    for(int j=0;j<C-1;j++)
    {
        space[j]=cow[j+1]-cow[j];
        //cout<<space[j]<<endl;
    }
    for(int k=0;k<C-1;k++)
    {
        copyspace[k]=space[k];
    }
    sort(copyspace,copyspace+C-1);
    int count1=0;
    while(count1!=M-1&&M<C)
    {
        for(int m=0;m<C-1;m++)
        {
            if(space[m]==copyspace[C-2-count1])
            {
                //cout<<copyspace[C-2-count1]<<endl;
                index[count1]=m;
                count1++;
                break;

            }

        }
    }

    sort(index,index+count1);
    for(int n=0;n<count1-1;n++)
    {
        //cout<<index[n]<<endl;
         result[n]=cow[index[n+1]]-cow[index[n]+1];
        //cout<<result[n]<<endl;
    }




    if(M>C)
        totalnumber=C;
    else if(M==1)
        totalnumber=cow[C-1]-cow[0]+1;
    else
    {
        result[count1-1]=cow[index[0]]-cow[0];
        result[count1]=cow[C-1]-cow[index[count1-1]+1];
        for(int l=0;l<count1+1;l++)
        {
            totalnumber+=result[l];
        }
        totalnumber+=M;
    }

    fout<<totalnumber<<endl;




    fin.close();
    fout.close();
    return 0;
}

