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
const int mod = 1000000007;
int main()
{
    in_T{
        int N,M,P;
        in_I(N);in_I(M);in_I(P);
        long long dp[P+1][N+1][M+1];
        for(int i = 0;i<=P;i++)
            for(int j = 0;j<=N;j++)
                for(int k = 0;k<=M;k++)
                    dp[i][j][k] = 0;

        dp[1][1][1] = 1;

        for(int i = 2;i<=P;i++){
            for(int j = 1;j<=N;j++){
                for(int k = 0;k<=min(N,M);k++){
                    dp[i][j][k] = dp[i-1][j][k-1];
                }
            }
        }
    }
}
