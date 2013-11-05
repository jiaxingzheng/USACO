/*
ID: xing6231
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
class Giver
{private:
	int give;
	int recvnum;
	int gain;
	int recv;
	int distribution;
	string name;

public:
    Giver()
    {

    }
	Giver(string name)
	{
		recv=0;
		this->name=name;
	}
	Giver(const Giver&giver)
	{
		this->give=giver.give;
		this->recvnum=giver.give;
		this->gain=giver.gain;
		this->recv=giver.recv;
		this->distribution=giver.distribution;
	}
	string getName() const
	{
		return name;
	}
	void setGive(int give)
	{
		this->give=give;
	}
	void setRecv(int recv)
	{
		this->recv+=recv;
	}
	int getRecv() const
	{
	    return recv;
	}
	void setRecvnum(int recvnum)
	{
		this->recvnum=recvnum;
		if(recvnum=0)
            give=0;
	}
	int getRecvnum() const
	{
		return recvnum;
	}
	void setGain()
	{
	    if(recvnum!=0)
            gain=give%recvnum+recv;
        else
            gain=recv;

	}
	int getDistribution()
	{
	    if(recvnum!=0)
            distribution=give/recvnum;
        else
            distribution=0;

		return distribution;
	}
	int getEarn()
	{
	    setGain();
		return gain-give;
	}



};



int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	string str;
	int NP;
	fin>>NP;
	Giver* givers=new Giver[NP];
	for(int i=0;i<NP;i++)
	{
		fin>>str;
		Giver g(str);
		givers[i]=g;

	}
	for(int j=0;j<NP;j++)
    {
        fin>>str;
        int k=0;
        int a,b;
        fin>>a>>b;
        while(k<NP)
        {
            if(givers[k].getName()==str)
            {
                givers[k].setGive(a);
                givers[k].setRecvnum(b);



                for(int l=0;l<givers[k].getRecvnum();l++)
                {
                    int m=0;
                    fin>>str;
                    while(m<NP)
                    {
                        if(givers[m].getName()==str)
                        {
                            givers[m].setRecv(givers[k].getDistribution());

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
    for(int n=0;n <NP;n++)
    {


        fout<<givers[n].getName()<<" "<<givers[n].getEarn()<<endl;

    }
    fin.close();
    fout.close();
    return 0;
}

