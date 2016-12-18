#include<iostream>
using namespace std;
long buff[10003];

long getSum(int n)
{
    long ans=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        ans+=i;
    }
    return ans;
}

int main()
{
    cout<<getSum(284);
    cout<<endl<<getSum(220)<<endl;
    for(int i=1;i<=10000;i++)
    {
        buff[i]=getSum(i);
    }
    long ans=0;
    for(int i=1;i<=10000;i++)
    {
        if( buff[i]<=10000 && i<buff[i] && i==buff[buff[i]])
        ans+=i+buff[i];
    }
    cout<<ans<<endl;
    return 0;
}
