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
    int n;
    cin>>n;
    long long ans = 0;
    for(int i = 1;i<=n/2;i++){
        if(n%i == 0)
            ans++;
    }
    for(long long r = 2;r<n;r++){
        long long n2 = n*(r-1);
        long long den = r*r;
        for(int i = 3;(den-1)<=n2;i++){
            if(n2 % (den-1) == 0){
                ans++;
            }
            den *= r;
        }
    }
    cout<<ans<<endl;
}
