/*
    Nimesh Ghelani (nims11)
    DP
    store the segment length for [i][j] and consider it when >=k
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
#include<cstring>
using namespace std;
char str1[1003], str2[1003];
int dp[1003][1003], eq_streak[2][1003];
int main()
{
    int k;
    while(1)
    {
        in_I(k);
        if(!k)return 0;
        in_S(str1);in_S(str2);
        int len1 = strlen(str1), len2 = strlen(str2);
        for(int i=0;i<=len1;i++)
            dp[i][0]=0;

        for(int j=0;j<=len2;j++)
            dp[0][j]=0, eq_streak[0][j] = 0, eq_streak[1][j] = 0;

        for(int i=1;i<=len1;i++)
        {
            int x = i%2;
            for(int j=1;j<=len2;j++)
            {
                eq_streak[x][j] = dp[i][j] = 0;

                if(str1[i-1] == str2[j-1])
                    eq_streak[x][j] = eq_streak[!x][j-1]+1;

                for(int K=k;K<=eq_streak[x][j];K++)
                    dp[i][j] = max(dp[i][j], dp[i-K][j-K]+K);
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        printf("%d\n", dp[len1][len2]);
    }
}
