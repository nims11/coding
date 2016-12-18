/*
ID: nimeshg1
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");
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
    int n,s;
    fin>>n>>s;
    int count=0;
    vector <int> results;
    for(int i=s+1;results.size()<n;i++)
    {
        count=0;
        for(int j=2;j<=10 && count!=2;j++)
        {
            string A=toBaseB(i,j);
            if(isPalin(A))
            count++;
        }
        if(count==2)
        results.push_back(i);
    }
    for(int i=0;i<n;i++)
    fout<<results[i]<<endl;
    return 0;
}
