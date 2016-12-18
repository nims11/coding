/*
ID: nimeshg1
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
string toBaseB(int n,int base)
{
    string x;
    while(n>0)
    {
        int y=n%base;
        char c;
        if(y<=9)
        c='0'+y;
        else
        c='A'+y-10;
        x.push_back(c);
        n/=base;
    }
    string y;
    for(int i=0;i<x.size();i++)
    y.push_back(x[x.size()-1-i]);
    return y;
}
bool isPalin(string B)
{
    for(int i=0;i<=B.length()/2;i++)
    if(B[i]!=B[B.length()-1-i])
    return false;
    return true;
}
int main()
{
    int b;
    fin>>b;

    for(int i=1;i<=300;i++)
    {
        string A=toBaseB(i,b);
        string B=toBaseB(i*i,b);
        if(isPalin(B))
        fout<<A<<" "<<B<<endl;
    }

}
