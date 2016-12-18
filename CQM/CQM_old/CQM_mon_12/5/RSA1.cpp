/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
long long mod;
long long pow2(long long r2,long long n)
{
    long long ans=1;
    while(n>0)
    {
        if((n&1)>0)
        ans=(ans*r2)%mod;
        n>>=1;
        r2=(r2*r2)%mod;
    }
    return ans%mod;
}
int main()
{
    in_T
    {
        long long e,n,c;
        in_L(e);in_L(n);in_L(c);
        mod = n;
        long long ETF;
        if(n==1)ETF = 1;
        else
        {
            ETF=n;
            int lt=sqrt(n);
            if(n%2==0)
                {
                    ETF-=ETF/2;
                    while(n%2==0)n/=2;
                }
            for(int i=3;i<=lt;i+=2)
            {
                if(n%i==0)
                {
                    ETF-=ETF/i;
                    while(n%i==0)n/=i;
                }
            }
            if(n>1)
            ETF-=ETF/n;
        }
        long long d=0,p;
        while(((d%ETF) * (e%ETF))%ETF != 1)
        d++;
        p = pow2(c,d);
        cout<<d<<" "<<p<<endl;
    }
}
