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
long long POW(long long r, long long n){
    long long ans = 1;
    while(n>0){
        if(n&1) ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int main(){
    long long n, k;
    in_L(n);
    in_L(k);
    long long finalVal = 1;
    for(int i = 1;i<k;i++){
        finalVal += i;
        if(finalVal > n){
            cout<<0<<endl;
            return 0;
        }
    }
    long long diff = n-finalVal;
    n = k + diff;
    k = min(n-diff, diff);
    long long n_k = n-k;
    long long num = 1, den = 1;
    for(long long i = n_k+1;i<=n;i++){
        num = MUL(num, i);
        den = MUL(den, (i-n_k));
    }
    long long ans = MUL(num, POW(den, mod-2));
    cout<<ans<<endl;
}
