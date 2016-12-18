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

long long getans(long long n){
    if(n <= 0)return 0;
    long long ret = 0;
    long long maxi = 0;
    for(long long x = 2;x<=n;x*=2){
        long long y = x;
        while(y <= n){
            ret++;
            y*=3;
        }
    }
    return ret+1;
}
int main(){
    in_T{
        long long L, R;
        in_L(L);
        in_L(R);
        printf("%lld\n", getans(R) - getans(L-1));
    }
}
