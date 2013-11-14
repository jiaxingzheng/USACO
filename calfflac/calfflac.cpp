/*
ID: xing6231
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

int main() {
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    string str,str1;
    string cpstr;
    while(!fin.eof())
    {
           getline(fin,str1);
           str+=str1;
           cpstr+=str1;
           str+='\n';
           cpstr+=' ';
    }
    str[str.length()-1]='\0';
    //cout<<str<<endl;

    for (int k= 0; k<str.length(); k++)
    {
        if (!((cpstr[k] >= 'a' && cpstr[k] <= 'z') || (cpstr[k] >= 'A' && cpstr[k] <= 'Z')))
            cpstr[k] = ' ';
        else if(cpstr[k] >= 'a' && cpstr[k] <= 'z')
            cpstr[k] = cpstr[k] - 'a' + 'A';
    }
    //cout<<cpstr<<endl;
    int i=1;
    int length=0;
    string s;
    while(i<cpstr.length())
    {
        //cout<<"i:"<<i<<endl;
        int j=0;
        int count1=0;
        int count2=0;
        do
        {
            j++;
            while(cpstr[i-j-count1]==' ')
            {
                count1++;
               // cout<<"1++"<<endl;
            }

            while(cpstr[i+j+count2]==' ')
            {
                 count2++;
                // cout<<"2++"<<endl;
            }

        }while(i-j-count1>=0&&i+j+count2<cpstr.length()&&cpstr[i-j-count1]==cpstr[i+j+count2]);
        //s=str.substr(i-j-count1,j+j+count1+count2);
        //cout<<s<<endl;
        if(j+j-1>length)
        {

            length=j+j-1;
            //cout<<cpstr[i]<<cpstr[i+1]<<cpstr[i-1]<<endl;
            if(cpstr[i]==cpstr[i+1]||cpstr[i]==cpstr[i-1]||cpstr[i]==' ')
                length--;
            /*for(int k=0;k<j+j+count2+count1-1;k++)
            {
                s[k]=str[i-j-count1+1+k];
            }*/
            while(cpstr[i-j-count1+1]==' ')
            {
                count1--;
            }
            while(cpstr[i+j+count2-1]==' ')
            {
                 count2--;
            }
            s=str.substr(i-j-count1+1,j+j+count1+count2-1);
            //cout<<s<<endl;
        }
        i++;

    }
    fout<<length<<endl;
    fout<<s<<endl;
    fin.close();
    fout.close();
    return 0;
}

//解题思路：枚举回文中心（考虑中心为空，中心为两个相同字母情形）

