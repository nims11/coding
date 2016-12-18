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
int n;

int fact[100010], inv[100010];
int POW(long long r, long long n){
    int ans = 1;
    while(n>0){
        if(n&1) ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
void gen_fact(){
    fact[0] = 1;
    inv[0] = POW(fact[0], mod-2);
    for(int i = 1;i<100010;i++){
        fact[i] = (i*1LL*fact[i-1])%mod;
        inv[i] = POW(fact[i], mod-2);
    }
}
long long C(int n, int k){
    return MUL(fact[n], MUL(inv[k], inv[n-k]));
}

struct Node{
    int idx, end;
    friend bool operator<(const Node &a, const Node &b);
}nodes[100010];

bool operator<(const Node &a, const Node &b){
    if(a.end != b.end) return a.end < b.end;
    return a.idx < b.idx;
}

int getans(int l, int r){
    if(l > r)
        return 1;
    int tot = r-l+1;
    Node x;
    x.idx = l;
    x.end = r;
    int mid = lower_bound(nodes, nodes+n, x) - nodes;
    if(nodes[mid].end > r){
        return 0;
    }
    mid = nodes[mid].idx;
    return MUL(C(tot-1, mid-l), MUL(getans(l, mid-1), getans(mid+1, r)));
}

int main(){
    gen_fact();
    in_T{
        in_I(n);
        int x;
        for(int i = 1;i<=n;i++){
            in_I(x);
            nodes[i-1].idx = i-1;
            nodes[i-1].end = i+x-1;
        }
        sort(nodes, nodes+n);
        printf("%d\n", getans(0, n-1));
    }
}
