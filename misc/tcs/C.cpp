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

int main(){
    long long x, y, va, vb;
    cin>>x>>y>>va>>vb;
    float t = (x*va + y*vb) / float(va*va + vb*vb);
    float xx = x - va*t;
    float yy = y - vb*t;
    printf("%.11f\n", sqrt(xx*xx + yy*yy));
}
