#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        long long m;
        cin>>m;
        int hrs=(9+m/60)%24;
        int min=m%60;
        cout<<"Scenario #"<<z<<": ";
        if(hrs<10)
        cout<<0;
        cout<<hrs<<":";
        if(min<10)
        cout<<0;
        cout<<min<<endl;
    }
    return 0;
}
