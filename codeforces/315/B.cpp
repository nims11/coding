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
int fact[5000], inv[5000];
int POW(long long r, long long n){
    int ans = 1;
    while(n>0){
        if(n&1) ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
void gen_fact(){
    fact[0] = 1;
    inv[0] = POW(fact[0], mod-2);
    for(int i = 1;i<5000;i++){
        fact[i] = (i*1LL*fact[i-1])%mod;
        inv[i] = POW(fact[i], mod-2);
    }
}
long long C(int n, int k){
    return MUL(fact[n], MUL(inv[k], inv[n-k]));
}
int main(){
    gen_fact();
    int n;
    cin>>n;
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    int res = 0;
    for(int i = 2;i<=n;i++){
        dp[i] = 0;
        for(int j = 0;j<i;j++){
            dp[i] = ADD(dp[i], MUL(C(i-1, j), dp[i-j-1]));
        }
    }
    for(int i = 0;i<n;i++){
        res = ADD(res, MUL(C(n, i), dp[i]));
    
    cout<<res<<endl;
}
