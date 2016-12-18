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
double dp[1001][1001], dp2[1001][1001], dpHor[1001][1001], dpVert[1001][1001];
double dpHorSum[1001][1001], dpVertSum[1001][1001];
int main()
{
    dp[1][1] = 1;
    dpHor[1][1] = 1;
    dpVert[1][1] = 1;
    for(int i = 1;i<=1000;i++){
        for(int j = 1;j<=1000;j++){
            if(i == 1 && j == 1);
            else{
                dp[i][j] = dp[i-1][j]*0.5+dp[i][j-1]*0.5;
                dpHor[i][j] = dp[i-1][j]*0.5+dpHor[i][j-1];
                dpVert[i][j] = dp[i][j-1]*0.5+dpVert[i-1][j];
            }
            dp2[i][j] = dp2[i-1][j]+dp2[i][j-1]+dp[i][j]-dp2[i-1][j-1];
            dpHorSum[i][j] = dpHorSum[i][j-1]+dpHor[i][j];
            dpVertSum[i][j] = dpVertSum[i-1][j]+dpVert[i][j];
        }
    }
    in_T{
        int N, M;
        in_I(N);in_I(M);
        if(N == 1 && M == 1)
            printf("%.8lf\n", 1.0f);
        else
        printf("%.8lf\n", dp2[N-1][M-1]+dpVertSum[N-1][M]+dpHorSum[N][M-1]+dpVert[N-1][M]+dpHor[N][M-1]);
    }
}
