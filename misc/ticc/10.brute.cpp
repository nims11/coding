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
    int N, M;
    cin>>N>>M;
    int dp[N][M+1];
    for(int i = 1;i<=M;i++){
        dp[0][i] = 1;
    }
    for(int i = 1;i<N;i++){
        for(int j = 1;j<=M;j++){
            dp[i][j] = 0;
            for(int k = 1;k<=M/j;k++)
                dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
        }
    }
    long long res = 0;
    for(int i = 1;i<=M;i++)
        res = (res + dp[N-1][i])%mod; 
    cout<<res<<endl;
}
