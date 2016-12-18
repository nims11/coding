#include<iostream>
using namespace std;
int main()
{
    long t;
    cin>>t;
    for(long z=1;z<=t;z++)
    {
        long long n,x,pre=1,min=1;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>x;
            pre+=x;
            if(pre<min)
            min=pre;
        }
        cout<<"Scenario #"<<z<<": ";
        cout<<(-min)+2<<endl;
    }
    return 0;
}
