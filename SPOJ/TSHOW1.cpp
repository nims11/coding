#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> ans;
        long long k;
        cin>>k;
        long long n=2;
        while(k>0)
        {
            if((k-1)%n<n/2)
            ans.push_back(5);
            else ans.push_back(6);
            k-=n;
            n*=2;
        }
        for(long long i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
        cout<<endl;
    }
}
