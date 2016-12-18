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
int p[200010], d[200010];
int n, k;
int main(){
    in_I(n);in_I(k);
    for(int i = 0;i<n;i++){
        in_I(p[i]);
        in_I(d[i]);
    }
    vector<int> xxx;
    for(int i= 0;i<n;i++)
        xxx.push_back(p[i]+d[i]);
    sort(xxx.begin(), xxx.end());
    long long tot = 0;
    for(int i = n-1, j = 0; i>=0;j++, i--){
        tot -= d[i];
        if(j<k){
            tot += xxx[i];
        }
    }
    tot = max(0LL, tot);
    cout<<tot<<endl;
}
