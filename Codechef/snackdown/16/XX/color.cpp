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
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

int n, k;
long long fact[60], inv[60];
int C(int n, int k){
    return MUL(fact[n], MUL(inv[n-k], inv[k]));
}
int getans(int idx, int k, int par=-1){
    if(k == 1)
        return 1;
    if(k > n)
        return 0;
    return C(n-1, k-1);
}
int POW(long long r, long long n){
    int ans = 1;
    while(n>0){
        if(n&1) ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int main(){
    fact[0] = 1;
    for(int i = 1;i<=55;i++){
        fact[i] = MUL(fact[i-1], i);
    }
    for(int i = 0;i<=55;i++)
        inv[i] = POW(fact[i], mod-2);
    in_T{
        in_I(n);
        in_I(k);
        int u, v;
        for(int i = 0;i<n-1;i++){
            in_I(u);in_I(v);
        }
        long long ans = 0;
        for(int i = 1;i<=k;i++){
            long long locAns = getans(1, i);
            locAns = MUL(locAns, MUL(fact[k], inv[k-i]));
            ans = ADD(ans, locAns);

        }
        printf("%lld\n", ans);
    }
}
