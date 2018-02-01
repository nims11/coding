#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int main(){
    in_T{
        int n,m;
        in_I(n);
        in_I(m);
        for(int i = 0;i<m;i++){
            int x, y;
            in_I(x);
            in_I(y);
        }
        printf(n%2 == 0?"yes\n": "no\n");
    }
}
