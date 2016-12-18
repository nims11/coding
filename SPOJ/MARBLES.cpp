/*
 * Multinomial application
 * The main part of the solution is how the combination is calculated without overflow
 */
#include<iostream>
using namespace std;
long long combi(long long n,long long k)
{
    long long unsigned ans=1;
    k=k>n-k?n-k:k;
    if(k==0)
    return 1;
    if(k==1)
    return n;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        n--;
        k--;
        cout<<combi(n,k)<<endl;
    }
    return 0;
}
