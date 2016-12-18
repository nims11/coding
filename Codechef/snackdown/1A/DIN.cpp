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
#define BE(a) a.begin(), a.end()

using namespace std;
int main()
{
    in_T{
        int N, D, K;
        in_I(N);in_I(D);in_I(K);
        double dp[D+1][N+1][K+1];
        int bk[D+1][N+1][K+1];
        memset(bk, -1, sizeof(bk));


        for(int i = 1;i<=D;i++){
            for(int j = 1;j<=N;j++){
                for(int k = 0;k<=j;k++){
                    dp[i][j][k] = max(dp[i][j-1][k-1], dp[i-1][j][k]);
                    if(dp[i][j][k] == dp[i-1][j-1][k-1])
                        bk[i][j][k] = 1;
                    else
                        bk[i][j][k] = 0;
                }
            }
        }
        printf("%.8lf\n", dp[D][N][K]);
        int ans[N];
        int curD, curN, curK;
        curD = D, curN = N, curK = K;
        while(bk[
    }
}
