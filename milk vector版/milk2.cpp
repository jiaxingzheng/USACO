/*
ID: xing6231
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include<vector>


using namespace std;

class Farmer
{public:
    int start;
    int endt;
public:
    Farmer()
    {

    }
    Farmer(int start,int endt)
    {
        this->start=start;
        this->endt=endt;
    }
    void print()
    {
        cout<<start<<" "<<endt<<endl;
    }

};
bool cmp(const Farmer &f1,const Farmer &f2){
    if(f1.start<f2.start)
        return true;
    if(f1.start==f2.start&&f1.endt<f2.endt)
        return true;
    return false;
}
int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N;
    fin>>N;
    vector<Farmer> farmer;
    int milkt=0;
    int nomilkt=0;
    int start;
    int endt;


    for(int i=0;i<N;i++)
    {
        fin>>start;
        fin>>endt;
        Farmer f(start,endt);
        farmer.push_back(f);
        //farmer[i].print();

    }
    sort(farmer.begin(),farmer.end(),cmp);
    vector<Farmer> farmer1;
    farmer1.push_back(farmer[0]);
    //farmer1[0].print();
    int k=1;
    int j;
    for(j=1;j<N;j++)
    {
        //farmer[j].print();

        bool flag=true;
        for(int l=0;l<k;l++)
        {
            if(farmer[j].start<=farmer1[l].endt)
            {
                if(farmer[j].endt>farmer1[l].endt)
                {
                    farmer1[l].endt=farmer[j].endt;
                }

                flag=false;
                break;

            }
        }
        if(flag)
        {

            farmer1[k].endt=farmer[j].endt;
            farmer1[k].start=farmer[j].start;
            //farmer1.push_back(farmer[j]);
            //farmer1[k].print();
            k++;

        }

    }
    for(j=0;j<k-1;j++)
    {
        if(milkt<farmer1[j].endt-farmer1[j].start)
            milkt=farmer1[j].endt-farmer1[j].start;
        if(nomilkt<farmer1[j+1].start-farmer1[j].endt)
            nomilkt=farmer1[j+1].start-farmer1[j].endt;
    }
    if(milkt<farmer1[j].endt-farmer1[j].start)
            milkt=farmer1[j].endt-farmer1[j].start;

    fout<<milkt<<" "<<nomilkt<<endl;





    fin.close();
    fout.close();
    return 0;
}

