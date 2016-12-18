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
int main()
{
    int cc = 0;
    in_T
    {
        cc++;
        int b;
        in_I(b);
        int n;
        in_I(n);
        int dp[2][2];
        dp[1][0] = n;
        dp[1][1] = 1;
        int maax[3] = {dp[1][0], 1, 2};
        for(int i=2;i<b;i++)
        {
            in_I(n);
            int x = i%2;
            int y = !x;
            if(dp[y][0]+n>=n)
            {
                dp[x][0] = dp[y][0]+n;
                dp[x][1] = dp[y][1];
            }else
            {
                dp[x][0] = n;
                dp[x][1] = i;
            }
            if(dp[x][0]>maax[0])
            {
                maax[0] = dp[x][0];
                maax[1] = dp[x][1];
                maax[2] = i+1;
            }else if(dp[x][0] == maax[0] && maax[2]-maax[1]<(i+1-dp[x][1]))
            {
                maax[0] = dp[x][0];
                maax[1] = dp[x][1];
                maax[2] = i+1;
            }
        }
        if(maax[0]<=0)
        {
            printf("Route %d has no nice parts\n", cc);
        }else
        {
            printf("The nicest part of route %d is between stops %d and %d\n", cc, maax[1], maax[2]);
        }
    }
}
