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
        if(A > B)
            swap(A, B), swap(C, D);
        B -= A;
        B %= C;
        D %= C;
        long long gcd = GCD(D, C);
        long long prev = (C - B)%C;
        long long prevVal = prev/gcd * gcd;
        long long ans = min((prevVal + B)%C, (prevVal+B+gcd)%C);
        long long ans2 = max((prevVal + B)%C, (prevVal+B-gcd+C)%C);
        ans = min(ans, (C-ans2));
        printf("%lld\n", ans);
    }
}
