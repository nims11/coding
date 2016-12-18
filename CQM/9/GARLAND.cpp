/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
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

using namespace std;
char str[100];
int len;
int dp[51][51][51][3][3];
const int MOD = 1000000007;
inline int add(int a, int b){
    return (a+b)%MOD;
}
int main()
{
    while(in_S(str) != EOF){
        int n[3] = {0};
        for(len=0;str[len];len++){
            n[str[len]-'A']++;
        }
        for(int i = 0;i<=n[0];i++){
            for(int j = 0;j<=n[1];j++)
                for(int k = 0;k<=n[2];k++)
                    for(int l = 0;l<3;l++)
                    dp[i][j][k][0][l] = dp[i][j][k][1][l] = dp[i][j][k][2][l] = 0;
        }
        if(n[0])
            dp[n[0]-1][n[1]][n[2]][0][0] = 1;
        if(n[1])
            dp[n[0]][n[1]-1][n[2]][1][1] = 1;
        if(n[2])
            dp[n[0]][n[1]][n[2]-1][2][2] = 1;

        for(int i = n[0];i>=0;i--){
            for(int j = n[1];j>=0;j--)
                for(int k = n[2];k>=0;k--)
                {
                    if(i == n[0] && j == n[1] && k == n[2])continue;
                    if(i+j+k == n[0]+n[1]+n[2]-1)continue;

                    for(int l = 0;l<3;l++){
                        if(i != n[0] && !(i+j+k==0 && l == 0)){
                            dp[i][j][k][0][l] = (dp[i][j][k][0][l] + dp[i+1][j][k][1][l])%MOD;
                            dp[i][j][k][0][l] = (dp[i][j][k][0][l] + dp[i+1][j][k][2][l])%MOD;
                        }

                        if(j != n[1] && !(i+j+k==0 && l == 1)){
                            dp[i][j][k][1][l] = (dp[i][j][k][1][l] + dp[i][j+1][k][0][l])%MOD;
                            dp[i][j][k][1][l] = (dp[i][j][k][1][l] + dp[i][j+1][k][2][l])%MOD;
                        }

                        if(k != n[2] && !(i+j+k==0 && l == 2)){
                            dp[i][j][k][2][l] = (dp[i][j][k][2][l] + dp[i][j][k+1][0][l])%MOD;
                            dp[i][j][k][2][l] = (dp[i][j][k][2][l] + dp[i][j][k+1][1][l])%MOD;
                        }
                    }
                }
        }
        long long ans = 0;
        for(int i = 0;i<3;i++)
            for(int j = 0;j<3;j++)
            ans = (ans+dp[0][0][0][i][j])%MOD;
        printf("%lld\n", ans);
    }
}
