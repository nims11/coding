/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int dp[1001][1001], maxPoss[1001];
int arr[1001], prev[1001];
const int mod = 1000000007;
int main()
{
    in_T{
        int N;
        in_I(N);
        for(int i = 0;i<N;i++)
            in_I(arr[i]);
        for(int i = 0;i<=N;i++)
            for(int j = 0;j<=N;j++)
                dp[i][j]  =0;
        maxPoss[0] = 1;
        for(int i = 0;i<=1;i++)
            dp[0][i] = 1;
        for(int i = 1;i<N;i++){
            maxPoss[i] = min(maxPoss[i-1]+1, arr[i]);
            for(int j = 1;j<=maxPoss[i];j++)
                dp[i][j] = (dp[i-1][j-1])%mod;
            for(int j = N-1;j>=0;j--)
                dp[i][j] = (dp[i][j+1]+dp[i][j])%mod;
        }
        printf("%d\n", dp[N-1][0]);
    }
}
