#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        bool flag=true;
        int spying[1000]={0};
        int n,r;
        cin>>n>>r;
        vector<int> spied;
        for(int i=0;i<r;i++)
        {
            int a,b;
            cin>>a>>b;
            spying[a]++;spied.push_back(b);
        }
        for(int i=0;i<spied.size();i++)
        {
            if(spying[spied[i]]>0)
            {
                flag=false;
                break;
            }
        }
        cout<<"Scenario #"<<z<<": ";
        if(flag)
        cout<<"spying\n";
        else
        cout<<"spied\n";
    }
    return 0;
}
