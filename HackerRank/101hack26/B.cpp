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
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
const double pi = acos(-1);
int GCD(int a,int b){
    while(b){
        swap(a, b);
        b %= a;
    }
    return a;
}
int main()
{
    in_T{
        int R, S;
        in_I(R);
        in_I(S);
        int n = R/S;
        int m = R%S;
        if(m*4LL <= S){
            long long T = 0;
            int num = m, deno = S;
            num /= GCD(m, S);deno /= GCD(m, S);
            printf("%lld %d/%d\n", T+R, num, deno);
        }else{
            printf("%lld %d/%d\n", (long long)S-m+R, 0, 1);
        }
    }
}
