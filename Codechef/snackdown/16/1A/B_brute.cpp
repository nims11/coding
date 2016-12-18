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
long long GCD(long long a,long long b){
    while(b){
        swap(a, b);
        b %= a;
    }
    return a;
}
int main(){
    in_T{
        long long A, B, C, D;
        in_L(A);in_L(B);in_L(C);in_L(D);
        long long ans = 1e18;
        for(int i = 0;i<=100;i++){
            for(int j = 0;j<=100;j++){
                ans = min(ans, abs(A+C*i - (B+D*j)));
            }
        }
        printf("%lld\n", ans);
    }
}
