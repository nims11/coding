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
int p[300010];
int last[300010];
int ivert[300010];
int main(){
    int n, m;
    in_I(n);
    in_I(m);
    for(int i = 1;i<=n;i++){
        in_I(p[i]);
        ivert[p[i]] = i;
    }
    for(int i = 0;i<m;i++){
        int x, y;
        in_I(x);
        in_I(y);
        if(ivert[x] > ivert[y])
            swap(x, y);
        last[y] = max(last[y], ivert[x]);
    }
    int curLen = 0;
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        int len = 1+min(curLen, i-last[p[i]]-1);
        ans += len;
        curLen = len;
    }
    cout<<ans<<endl;
}
