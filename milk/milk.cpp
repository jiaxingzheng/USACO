/*
ID: xing6231
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>


using namespace std;
struct farmer{
    int price;
    int milk;
};
bool cmp(const farmer&f1,const farmer&f2)
{
    if(f1.price<f2.price)
        return true;
    return false;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int N,M;
    fin>>N>>M;
    int price=0;
    int milk=0;

    farmer f[5000];
    for(int i=0;i<M;i++)
    {
        fin>>f[i].price>>f[i].milk;
    }
    sort(f,f+M,cmp);
    for(int j=0;j<M;j++)
    {
        //cout<<j<<" "<<f[j].price<<endl;

        if(N-milk>f[j].milk)
        {
            milk+=f[j].milk;
            //cout<<milk<<endl;
            price+=f[j].milk*f[j].price;
            //cout<<price<<endl;
        }
        else
        {

            price+=f[j].price*(N-milk);
            //cout<<milk<<endl;
            //cout<<price<<endl;
            break;
        }


    }
    fout<<price<<endl;
    fin.close();
    fout.close();
    return 0;
}

