#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cout.precision(2);
    while(t--)
    {
        int n;
        cin>>n;
        double ans=1;
        for(int i=1;i<n;i++)
        {
            ans+=n/double(n-i);
        }
        cout<<fixed<<ans<<endl;
    }
}
