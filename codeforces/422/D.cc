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
const int mod = 1000000007;
#define MUL(a, b) (((a) * 1LL * (b)) % mod)
#define ADD(a, b) (((a) + 0LL + (b)) % mod)

#define MAX_N 5000010
int sieve[MAX_N+1];
void genPrimes(){
    for(int i = 0; i<=MAX_N; i++)
        sieve[i] = i;

    for(int i = 2;i<=MAX_N;i++){
        if(sieve[i] == i){
            if(i*1LL*i <= MAX_N)
            for(int j = i*i;j<=MAX_N;j+=i)
                sieve[j] = min(sieve[j], i);
        }
    }
}
int dp[MAX_N];
int getans(int x){
    if(dp[x] != -1)
        return dp[x];
    int &ans = dp[x];
    if(sieve[x] == x){
        return (ans = (x * 1LL * (x-1) / 2) % mod);
    }else{
        int cur = sieve[x];
        int left = x/cur;
        return (ans = ADD(getans(left), MUL(left, getans(cur))));
    }
}

int main(){
    int t, l, r;
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    genPrimes();
    cin>>t>>l>>r;
    long long xxx = 1;
    long long ans = 0;

    for(int i = l; i <= r;i++){
        ans = ADD(ans, MUL(xxx, getans(i)));
        xxx = MUL(xxx, t);
    }
    cout<<ans<<endl;
}
