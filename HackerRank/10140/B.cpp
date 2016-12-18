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
int h[100010];
int x[100010];
int main(){
    int n;
    in_I(n);
    for(int i= 1;i<=n;i++)
        in_I(h[i]);
    int m;
    in_I(m);
    for(int i = 1;i<=m;i++)
        in_I(x[i]);
    sort(x+1, x+m+1);
    x[0] = 1;
    for(int i1 = 1;i1<=m;i1++){
        int pos = x[i1];
        int prevPos = x[i1-1];
        for(int i2 = prevPos; i2 < pos; i2++){
            h[i2] = min(h[i2], pos - i2);
        }
    }
    long long ans = 0;
    for(int i = 1;i<=n;i++)
        ans += h[i];
    printf("%lld\n", ans);
}
