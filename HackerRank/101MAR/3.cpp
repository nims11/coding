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
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
int fact[100010], inv[100010];
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
long long C(int n, int r){
    // cout<<n<<" "<<r<<endl;
    if(r < 0)return 0;
    long long ret = fact[n];
    ret = (ret * inv[n-r])%mod;
    ret = (ret * inv[r])%mod;
    return ret;
}
long long cat(int m, int n){
    long long ret = C(m+n, m) - C(m+n, m-1);
    ret %= mod;
    if(ret < 0)ret += mod;
    // cout<<m<<" "<<n<<" "<<ret<<endl;
    return ret;
}
int main()
{
    fact[0] = 1;
    for(int i = 1;i<=100000;i++)
        fact[i] = (fact[i-1]*1LL*i)%mod;
    for(int i = 0;i<=100000;i++)
        inv[i] = POW(fact[i], mod-2);
    in_T{
        int N;
        in_I(N);
        if(N%2 == 1){
            printf("0\n");
            continue;
        }
        int res = 0;
        for(int m = 0, n = N-1; n > m; n--, m++){
            res = (res + cat(m, n))%mod;
        }
        printf("%d\n", res);
    }
}
