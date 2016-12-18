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
#define MUL(a, b) (((a)*1LL*(b))%mod)
#define ADD(a, b) ((a+b)%mod)
int fact[4010], inv[4010];
int POW(long long r, long long n){
    int ans = 1;
    vector<int> a;
    while(n>0){
        if(n&1) ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int C(int n, int k){
    return MUL(fact[n], MUL(inv[n-k], inv[k]));
}
int dp[4010];
int dp2[4010][4010];
int getans(int n, int N){
    int ret = C(N, n);
    return MUL(ret, dp[n]);
}
int main(){
    int n;
    in_I(n);
    fact[0]=1;
    for(int i = 1;i<=4000;i++)
        fact[i] = MUL(fact[i-1], i);
    for(int i = 0;i<=4000;i++)
        inv[i] = POW(fact[i], mod-2);
    
    dp[0] = 1;
    dp2[0][0] = 1;
    for(int i = 1;i<=n;i++){
        dp2[i][0] = 1;
        dp[i] = 1;
        for(int j = 1;j<=i;j++){
            dp2[i][j] = ADD(dp2[i-1][j-1], MUL(dp2[i-1][j], j+1));
            j!=i && (dp[i] += dp2[i][j]);
        }
    }
    int res = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=i;j++)
            cout<<dp2[i][j]<<" ";
        cout<<endl;
        // res = ADD(res, getans(i, n));
    }
    cout<<dp[n]<<endl;
}
