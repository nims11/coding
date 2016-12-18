#include<iostream>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        bool flag=true;
        int n,r;
        cin>>n>>r;
        map<int, set <int> > studs;
        for(int i=0;i<r;i++)
        {
            int a,b;
            cin>>a>>b;
            pair< set<int>::iterator ,bool> x = studs[a].insert(b);
            if(!x.second){flag=false;break;}
        }

        cout<<"Scenario #"<<z<<": ";
        if(flag)
        cout<<"possible\n";
        else
        cout<<"impossible\n";
    }
}



