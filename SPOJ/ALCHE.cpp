#include<iostream>
using namespace std;
int main()
{
    long long unsigned n,m;
    while(cin>>n>>m)
{
        if(n!=-1)
        {
            if(n*37==m*1000)
            cout<<"Y\n";
            else
            cout<<"N\n";
        }
        else
        break;

    }    return 0;
}
