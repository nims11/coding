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
    in_T{
        int N, M, K;
        in_I(N);in_I(M);in_I(K);
        long long ans = 0;
        for(int i = 0;i<N;i++){
            int x;
            in_I(x);
            int times = min(M, x/K);
            ans = ADD(ans, x - (times*K));
        }
        cout<<ans<<endl;
    }
}
