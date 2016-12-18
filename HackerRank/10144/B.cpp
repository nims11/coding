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
int f(int n){
    if(n == 2)return 1;
    return ADD((n-1), MUL(f(n-1), (n-2)));
}
int POW(long long r, long long n){
    int ans = 1;
    while(n>0){
    if(n&1) ans = MUL(ans, r);
    n >>= 1;
    r = MUL(r, r);
    }
    return ans;
}
int fact[100010], inv[100010];
void gen_fact(){
    fact[0] = 1;
    inv[0] = POW(fact[0], mod-2);
    for(int i = 1;i<100010;i++){
        fact[i] = MUL(i, fact[i-1]);
        inv[i] = POW(fact[i], mod-2);
    }
}
int main(){
    gen_fact();
    int n;
    in_I(n);
    long long ans = 0;
    for(int i = 2;i<=n;i++){
        ans = ADD(ans, MUL(fact[i-1], MUL(fact[n-2], inv[i-2])));
    }
    printf("%lld\n", MUL(ans, n));
}
