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
        int n,m,k;
        in_I(n);
        in_I(m);
        in_I(k);
        int diff = abs(n-m);
        if(k>=diff){
            cout<<0<<endl;
        }else{
            cout<<(diff-k)<<endl;
        }
    }
}
