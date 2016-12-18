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
#define ADD(a, b) (a+b)%mod;
using namespace std;
int dp[301][1801][10];
const int mod = 1000000007;
int main()
{
    dp[0][0][0] = 1;
    for(int i = 1;i<=300;i++){
        for(int j = 0;j<=1800;j++){
            for(int l = 0;l<=9;l++){
                dp[i][j][l] = dp[i-1][j][l]; // 0
                if(l>0)
                    dp[i][j][l] = ADD(dp[i][j][l], dp[i-1][j][l-1]);
                if(j-4 >= 0)
                    dp[i][j][l] = ADD(dp[i][j][l], dp[i-1][j-4][l]);
                if(j-6 >= 0)
                    dp[i][j][l] = ADD(dp[i][j][l], dp[i-1][j-6][l]);
            }
        }
    }
    in_T{
        int R, B, L;
        in_I(R);in_I(B);in_I(L);
        if(R > 1800)
            printf("0\n");
        else{
            int res = 0;
            for(int i = 0;i<=L;i++){
                res = (res + dp[B][R][i])%mod;
            }
            printf("%d\n", res);
        }
    }
}
