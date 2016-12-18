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
long long fact[101];
int main()
{
    fact[0] = 1;
    for(int i = 1;i<=100;i++){
        fact[i] = (i*fact[i-1])%mod;
    }
    int z=  0;
    in_T{
        z++;
        int M, N;
        cin>>M>>N;
       long long dp[N+1][M+1];
        for(int i = 0;i<=N;i++)
            for(int j = 0;j<=M;j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++){
                dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1])%mod;
            }
        cout<<"Case #"<<z<<": ";
        cout<<(fact[M]*dp[N][M])%mod<<endl;
    }
}
