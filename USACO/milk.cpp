/*
ID: nimeshg1
PROG: milk
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream fin("milk.in");
ofstream fout("milk.out");
struct farmer{
int p,a;
friend bool operator<(const struct farmer &a,const struct farmer &b)
{
    return a.p<b.p;
}
};
int main()
{
    int n,m;
    fin>>n>>m;
    vector<struct farmer> farmers;
    for(int i=0;i<m;i++)
    {
        struct farmer x;
        fin>>x.p>>x.a;
        farmers.push_back(x);
    }
    sort(farmers.begin(),farmers.end());
    int total=0,price=0;
    for(int i=0;i<m;i++)
    {
        if(total+farmers[i].a>=n)
        {
            price+=(n-total)*farmers[i].p;
            total=n;
            break;
        }else
        {
            total+=farmers[i].a;
            price+=farmers[i].p*farmers[i].a;
        }
    }
    fout<<price<<endl;
    return 0;
}
