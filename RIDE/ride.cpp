/*
ID: xing6231
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string str0,str;
	getline(fin,str0);
	getline(fin,str);		
		int j=0;
		int a=1;	
		while(str0[j]!='\0')
		{
			a*=str0[j]-64;
			j++;
		}
	    int k=0;
		int b=1;	
		while(str[k]!='\0')
		{
			b*=str[k]-64;
			k++;
		}

	
	


	if(a%47==b%47)
        fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;
	
    return 0;
}

