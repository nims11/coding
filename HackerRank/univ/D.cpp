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
        int n;
        in_I(n);
        int o = 0, e = 0;
        while(n--){
            int m, k;
            in_I(m); in_I(k);
            if(m%2)
                o++;
            else if(m != 2)e++;
        }
        printf(o%2 == 0 && e%2 == 0?"BEN\n":"BOB\n");
    }
}
