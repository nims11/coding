/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int mod = 1000000007;
long long poww(long long r2,long long n)
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
    long long inv = poww(25, mod-2);
    in_T
    {
        int n;
        in_I(n);
        long long ans = poww(26, n/2)-1;

//        cout<<ans<<endl;
        if(ans<0)
            ans += mod;
        ans = (ans*inv)%mod;
        ans = (ans*26)%mod;
        ans = (ans*2)%mod;
        if(n%2)
        {
            ans = (ans + poww(26, (n+1)/2))%mod;
        }
        printf("%lld\n", ans);
    }
}
