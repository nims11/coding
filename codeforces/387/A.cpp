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
    int n;
    in_I(n);
    int ans = -1;
    for(int a = 1;a*a<=n;a++){
        if(n % a == 0)
            ans = a;
    }
    cout<<ans<<" "<<n/ans<<endl;
}
