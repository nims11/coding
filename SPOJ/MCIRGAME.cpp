#include<iostream>
#include<iomanip>
using namespace std;
long double dp[151]={0};
long double getans(int n)
{
    if(dp[n]!=0)return dp[n];
    if(n==0)
    return 0.0f;

    long double ans=0.0f;
    for(int i=2;i<=2*n;i+=2)
    {
        ans+=getans((i-2)/2)*getans((2*n-i)/2);
    }
    dp[n]=ans;
    return ans;
}
int main()
{
    dp[0]=1.0f;dp[1]=1.0f;dp[2]=2.0f;
    int n;
    cout.precision(0);
    cout<<fixed;
    while(cin>>n)
    {
        if(n==-1)
        return 0;
        cout<<getans(n)<<endl;
    }
}

