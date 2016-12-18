#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,m,n;
        cin>>a>>b>>n>>m;
        long long ans=a;
        n-=1;
        while(n--)
        {
            ans=(ans+b)%m;
            b=b+a;
            a=b-a;
            b=b%m;
            a=a%m;
        }
        cout<<ans<<endl;
    }
}
