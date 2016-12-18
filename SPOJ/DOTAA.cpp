#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,d;
        cin>>n>>m>>d;
        vector<int> HP;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            HP.push_back(x);
        }
        bool possible=true;
        sort(HP.begin(),HP.end());
        int curr=n-1;
        for(int i=0;i<m;i++)
        {
            if(HP[curr]<=d)
            {
                curr--;
                if(HP[curr]<=d)
                {possible=false;
                break;}
                else
                i--;
            }else
            HP[curr] -= d;
        }
        if(possible)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    return 0;
}
