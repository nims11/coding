#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;

int main(){
    long long n, k;
    cin>>n>>k;
    long long ans = n;
    k-= 1;
    if(k){
        long long cur = 1;
        while(cur <= n)
            cur <<= 1;
        ans = cur-1;
    }
    cout<<ans<<endl;
}
