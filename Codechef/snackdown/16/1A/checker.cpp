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
    for(int i = 100000;i>=0;i--){
        int n;
        in_I(n);
        assert(n <= 100);
        int arr[n+1];
        for(int i = 1;i<=n;i++)
            in_I(arr[i]);
        int dp[n+1][n+1];
        for(int i = 0;i<=n;i++)
            for(int j = 0;j<=n;j++)
                dp[i][j] = 0, dp[i][1] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
                if(arr[i] > arr[j]){
                    for(int k = 2;k<=i;k++)
                        dp[i][k] += dp[j][k-1];
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<=n;i++){
            int local = 0;
            for(int j = 1;j<=n;j++){
                local += dp[j][i];
            }
            if(local)
                ans = local;
        }
        cout<<i<<endl;
        assert(ans == i);
        sort(arr+1, arr+n+1);
        for(int i = 1;i<=n;i++)
            assert(arr[i] == i);
    }
}
