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
#define ADD(a, b) ((a+0LL+b)%mod)
int C[1001][1001];
void gen_C(){
    for(int i = 0;i<1001;i++)
    C[i][0] = C[i][i] = 1;
    for(int i = 0;i<1001;i++)
    for(int j = 0;j<1001;j++)
        C[i][j] = ADD(C[i-1][j-1], C[i-1][j]);
}
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+0LL+b)%mod)
long long fact[15];
void gen_fact(){
    fact[0] = 1;
    for(int i = 1;i<15;i++){
        fact[i] = (i * 1LL * fact[i-1]);
    }
}
long long dp[20][20][20];
long long f(int len, int t, int n){
    if(dp[len][t][n] != -1)
        return dp[len][t][n];
    if(n == 0){
        if(len == 0){
            return 1;
        }
        return 0;
    }
    long long &ans = dp[len][t][n];
    ans = 0;
    for(int i = 0;i<=min(len, t);i++){
        ans += C[len][i] * f(len-i, t, n-1);
    }
    return ans;
}
long long f2(int len, int t){

}
int main(){
    gen_C();
    gen_fact();
    int k, t;
    in_I(k);
    in_I(t);
    int len = 1;
    while(true){

    }
}
