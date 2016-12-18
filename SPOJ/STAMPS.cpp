#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        long stampsNeeded;int nFrnd;
        vector <int> amt;
        cin>>stampsNeeded>>nFrnd;
        for(int i=0;i<nFrnd;i++)
        {
            int x;
            cin>>x;
            amt.push_back(x);
        }
        sort(amt.begin(),amt.end());

        long sum=0;
        bool possible=false;
        int count=0;
        for(int i=nFrnd-1;i>=0;i--)
        {
            sum+=amt[i];
            count++;
            if(sum>=stampsNeeded)
            {
                possible=true;
                break;
            }
        }
        if(possible)
        cout<<"Scenario #"<<z<<":"<<endl<<count<<endl;
        else
        cout<<"Scenario #"<<z<<":"<<endl<<"impossible"<<endl;
cout<<endl;
    }
    return 0;
}
