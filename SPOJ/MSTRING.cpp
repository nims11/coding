/*
    Nimesh Ghelani (nims11)
    DP
    dp[i][j] = length of shortest subsequence which ends with str1[i] and is not present in str2[0..j]
             = 1 if str1[i] doesn't occur in str2[0..j]
             = 1 + min(dp[x<=i][position of latest str1[i] in str2[0..j]])
    Compress dp array to save time.
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
const int INF = 1e9;
using namespace std;
char str1[1001], str2[1001];
int len1, len2;
int prev_occ[26];
int dp_curr[1001];
int dp_pre[1001];
int res = INF;
int main()
{
    in_S(str1);
    in_S(str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    for(int i=0;i<len2;i++)
        dp_pre[i] = dp_curr[i] = INF;
    for(int i=0;i<len1;i++)
    {
        for(int z=0;z<26;z++)
            prev_occ[z] = -1;
        for(int j=0;j<len2;j++)
        {
            prev_occ[str2[j]-'a'] = j;
            int x = prev_occ[str1[i]-'a'];
            if(x == -1)
                dp_curr[j] = 1;
            else
            {
                if(x == 0)
                {
                    if(i == 0)
                        dp_curr[j] = INF;
                    else
                        dp_curr[j] = 2;
                }
                else if(dp_pre[x-1] == INF)
                    dp_curr[j] = INF;
                else
                    dp_curr[j] = 1 + dp_pre[x-1];
            }
            dp_curr[j] = min(dp_curr[j], dp_pre[j]);
        }
        res = min(res, dp_curr[len2-1]);
        for(int z=0;z<len2;z++)
        {
//            cout<<dp_curr[z]<<" ";
            dp_pre[z] = min(dp_pre[z], dp_curr[z]);
        }
        newline;
    }
    printf("%d\n", res);
}
