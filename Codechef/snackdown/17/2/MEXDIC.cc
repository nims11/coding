#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int arr[500010];
long long dp[500010];
int count_[500010];
int tot = 0;
const int mod = 1000000007;
#define MUL(a, b) (((a)*1LL*(b))%mod)
#define ADD(a, b) ((a+0LL+b)%mod)
int POW(long long r, long long n){
    if(n < 0)
        return 0;
    int ans = 1;
    while(n>0){
    if(n&1) ans = MUL(ans, r);
    n >>= 1;
    r = MUL(r, r);
    }
    return ans;
}
int main(){
    int n, k;
    in_I(n);
    in_I(k);
    for(int i = 1;i<=n;i++)
        in_I(arr[i]);
    if(k > n){
        printf("%d\n", POW(2, n-1));
        return 0;
    }
    dp[0] = 0;
    int st = 0, end = 0;
    for(int i = 1;i<=n;i++){
        end++;
        if(arr[i] <= k){
            count_[arr[i]]++;
            if(count_[arr[i]] == 1){
                tot++;
            }
        }

        dp[i] = MUL(dp[i-1], 2);

        if(tot == k+1){
            if(st == 0){
                st = 1;
                dp[i] = ADD(dp[i], 1);
            }
            while(tot == k+1){
                if(arr[st] <= k){
                    count_[arr[st]]--;
                    if(count_[arr[st]] == 0){
                        count_[arr[st]]++;
                        break;
                    }
                }
                long long x = POW(2, (st-1));
                x -= dp[st];
                x %= mod;
                if(x < 0)
                    x += mod;
                dp[i] = ADD(dp[i], x);
                st++;
            }
        }
        /* cout<<dp[i]<<endl; */
    }
    long long ans = POW(2, n-1);
    ans -= dp[n];
    ans %= mod;
    if(ans < 0)
        ans += mod;
    printf("%lld\n", ans);
}
