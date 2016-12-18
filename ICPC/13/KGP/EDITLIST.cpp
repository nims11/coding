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
int m, n, x;
int list1[102], list2[102];
int dp[101][101];
int main()
{
    in_T
    {
        for(int i = 0;i<101;i++)
            list1[i] = list2[i] = 0;
        in_I(m);
        for(int i = 0;i<m;i++)
        {
           in_I(list1[i]);
        }
        in_I(n);
        for(int i = 0;i<n;i++)
        {
           in_I(list2[i]);
        }
        for(int i = 0;i<=m;i++)
            dp[i][0] = i;
        for(int i = 0;i<=n;i++)
            dp[0][i] = i;
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                int a = dp[i-1][j-1]+(list1[i-1] == list2[j-1]?0:1);
                int b = 1 + dp[i][j-1];
                int c = 1 + dp[i-1][j];
                dp[i][j] = min(a, min(b, c));
            }
        }
        printf("%d\n", dp[m][n]);
    }
}
