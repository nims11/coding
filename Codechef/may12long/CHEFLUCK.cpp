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
        long long ans=-1;
        for(long long i=7*(n/7);i>=0;i-=7)
        {
            if((n-i)%4==0)
            {
                ans=i;
                break;
            }
            if(i==0)
            break;
        }
        cout<<ans<<endl;
    }
}
