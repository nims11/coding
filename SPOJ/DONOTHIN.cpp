#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    while(n!=-1)
    {
        long ans=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ans+=x*(n-i);
        }

        cout<<ans*m<<endl;
        cin>>n>>m;
    }

    return 0;
}
