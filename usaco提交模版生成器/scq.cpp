#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    string name;
    cin>>name;
    string mkdir="md ";
    string path="C:\\Users\\Administrator\\Desktop\\USACO\\";

    path+=name;
    mkdir+=path;
    const char *direct=mkdir.c_str();
    system(direct);
    path+="\\";
    path+=name;
    string cpp=path,in=path,out=path;
    cpp+=".cpp";
    in+=".in";
    out+=".out";
    const char *cdirect=cpp.c_str();
    const char *idirect=in.c_str();
    const char *odirect=out.c_str();
    ifstream fin("C:\\Users\\Administrator\\Desktop\\USACO\\test\\test.cpp");
    string test;
    getline(fin,test,'$');
    test.replace(test.find("test"),4,name);
    test.replace(test.find("test",test.find("test")+5),4,name);
    test.replace(test.find("test",test.find("test",test.find("test")+5)+5),4,name);
    ofstream fout(cdirect);
    fout<<test;
    ofstream fout1(idirect);
    ofstream fout2(odirect);
    fin.close();
    fout.close();
    fout1.close();
    fout2.close();
    string start="start ";
    start+=cpp;
    const char* open=start.c_str();
    system(open);

    return 0;


}

