/*
    Nimesh Ghelani (nims11)
    DP
    dp[i] -> answer till ith index
    if no previous occurance of ith character, simply 2 times the previous dp state
    else 2 times the previous dp minus the dp value before the previous occurance.
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
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
char str[100002];
long long dp[100002];
int mod = 1000000007;
int main()
{
    in_T
    {
        in_S(str);
        dp[0] = 1;
        int foo[26];
        for(int i=0;i<26;i++)
            foo[i] = -1;
        int i=1;
        for(;str[i-1];i++)
        {
            if(foo[str[i-1]-'A'] == -1)
            {
                dp[i] = (2*dp[i-1])%mod;
            }else
            {
                dp[i] = (2*dp[i-1] - dp[foo[str[i-1]-'A']-1])%mod;
                if(dp[i]<0)
                    dp[i]+=mod;
            }
            foo[str[i-1]-'A'] = i;
        }
        printf("%lld\n", dp[i-1]);
    }
}
