/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
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
#define BE(a) a.begin(), a.end()

using namespace std;
int mod = 1000000007;
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int fact[1000001], inv[10000001];
inline int mul(int a, int b){
    return (a*1LL*b)%mod;
}
inline int C(int n, int r){
    int ret = 1;
    int den = 1;
    for(int i = r+1;i<=n;i++){
        ret = (ret * 1LL * i)%mod;
        den = (den * 1LL * (n-i+1))%mod;
    }
    return mul(ret, POW(den, mod-2));
}
int getans(int N){
    int res = 0;
    for(int i = 1;i<=N;i++){
        if((N-i)%2 == 0){
            int x = (N-i)/2;
            if(x-6>=0){
                res = (res + C(x-1, x-6))%mod;
            }
        }
    }
    return res;
}
int main()
{
    in_T{
        int N;
        in_I(N);
        printf("%d\n", getans(N));
    }
}
