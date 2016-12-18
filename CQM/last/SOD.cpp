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
long long dp[10][90];
int main()
{
    for(int i = 1;i<=9;i++){
        dp[1][i] = 1;
    }
    for(int i = 2;i<=9;i++){
        for(int j = 0;j<10;j++){
            for(int k = 1;k<90;k++){
                if(k-j > 0){
                    dp[i][k] += dp[i-1][k-j];
                }
            }
        }
    }
    for(int i = 2;i<=9;i++)
        for(int j = 1;j<=90;j++)
            dp[i][j] += dp[i-1][j];
    dp[9][1]++;
    in_T{
        int S;
        in_I(S);
        printf("%lld\n", dp[9][S]);
    }
}
