#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+0LL+b)%mod)
int POW(long long r, long long n){
    int ans = 1;
    while(n>0){
    if(n&1) ans = MUL(ans, r);
    n >>= 1;
    r = MUL(r, r);
    }
    return ans;
}
using namespace std;
pair<long long, long long> cur;
long long GCD(long  long a,long long b){
    while(b){
    swap(a, b);
    b %= a;
    }
    return a;
}
void normalize(){
    long long x = GCD(cur.first, cur.second);
    cur.first /= x;
    cur.second /= x;
}

int main(){
    long long k, pa, pb;
    cin>>k>>pa>>pb;

    // Case 1
    cur = {(pa + pb)*(k*pb + pa), pb * pb};
    normalize();

    // Case 2
}
