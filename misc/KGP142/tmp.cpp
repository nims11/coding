#include <cstdio>
#include <cassert>
 
#define T_LIMIT 100000
#define N_LIMIT 100000
#define K_LIMIT 100000
 
#define N 111111
#define K 350
#define MOD 1000000007
 
int dp[N][K];
 
int mul(int a, int b) {
    long long x = a;
    x *= b;
    x %= MOD;
    return (int)x;

}
 
int main() {
     
    for(int i=0; i<K; i++) dp[1][i] = 1;
    for(int i=2; i<N; i++) {
        dp[i][0] = 0;
        for(int j=1; j<K; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            if(dp[i][j] >= MOD) {
                dp[i][j] -= MOD;

            }

        }

    }
     
    int t;
    scanf("%d", &t);
     
    assert(1 <= t && t <= T_LIMIT);
     
    while(t--) {
        int n, k;
        scanf("%d%d", &n, &k);
         
        assert(1 <= n && n <= N_LIMIT);
        assert(1 <= k && k <= K_LIMIT);
         
        if(n == 1) {
            printf("-1\n");
            continue;

        }
         
        int ans = 0;
        for(int i = 1; i<K; i++) {
            int hi = k/i;
            if(hi >= i) {
                ans += mul((hi - i + 1), dp[n-1][i]);
                if(ans >= MOD)
                    ans -= MOD;

            }

        }
         
        printf("%d\n", ans);

    }

}
