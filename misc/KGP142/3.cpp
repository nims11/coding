
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
int mod = 1000000007;
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int C[1001][1001];
int main()
{
    for(int i = 0;i<=1000;i++)
        C[i][0] = 1;
    for(int i = 1;i<=1000;i++)
        for(int j = 1;j<=1000;j++)
            C[i][j] = (C[i][j-1]+C[i-1][j])%mod;
/*    for(int i = 0;i<=1000;i++)
        for(int j = 1;j<=1000;j++)
            C[i][j] = add(C[i][j-1], C[i][j]);*/
    in_T{
        int n, k;
        in_I(n);
        in_I(k);
        int limit = sqrt(k);
        int res = C[limit][n];
        for(int i = limit+1;i<=k;i++){
            int poss = k/i;
            res = (res+C[poss][n-1])%mod;
        }
        printf("%d\n", res);
    }
}
