#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long ans=(((n*(n-1))/2)%1000007+(n*(n+1))%1000007)%1000007;
        cout<<ans<<endl;
    }
    return 0;
}
