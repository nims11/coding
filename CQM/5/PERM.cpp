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
int sieve[1000001];
int dp[1000001];
const int mod = 1000000007;
int n;
const int lt = sqrt(1000000)+1;
int main()
{
    sieve[2] = 0;
    for(int i = 2;i<lt;i++)
        if(!sieve[i])
    {
        for(int j = i*i;j<=1000000;j+=i)
            sieve[j] = 1;
    }
    dp[1] = 1;
    int pre = 1;
    for(int i = 2;i<=1000000;i++)
    {
//        if(sieve[i] == 0)
//            cout<<i<<endl;
        pre += (!sieve[i]);
        dp[i] = (pre*1LL*dp[i-1])%mod;
    }
//    cout<<pre<<endl;
    in_T
    {
        in_I(n);
        printf("%d\n", dp[n]);
    }
}
