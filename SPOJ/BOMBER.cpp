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
int dp[101][101][2],m,n;
int even_check[] = {15,0,3,5,9,6,10,12};
int ec_sz = sizeof(even_check)/sizeof(int);
int odd_check[] = {7,11,13,14,8,4,2,1};
int oc_sz = sizeof(odd_check)/sizeof(int);
bool getans(int m, int n, bool odd = true)
{
    if(dp[m][n][!odd] != -1)
        return dp[m][n][!odd];
    if(m == 0 || n == 0)
        return !odd;
    if(m == 1 || n == 1)
        return odd;

    bool res[4][2];
    for(int i=1;i<=m/2;i++)
        for(int j=1;j<=n/2;j++)
    {
        res[0][0] = getans(i-1, j-1, true);
        res[0][1] = getans(i-1, j-1, false);
        res[1][0] = getans(i-1, n-j, true);
        res[1][1] = getans(i-1, n-j, false);
        res[2][0] = getans(m-i, j-1, true);
        res[2][1] = getans(m-i, j-1, false);
        res[3][0] = getans(m-i, n-j, true);
        res[3][1] = getans(m-i, n-j, false);
        bool ret = false;
        if(odd)
        {
            for(int k=0;k<ec_sz && !ret;k++)
                ret |= res[0][(even_check[k]&1)] && res[1][((even_check[k]>>1) & 1)] && res[2][((even_check[k]>>2)&1)] && res[3][((even_check[k]>>3)&1)];
        }else
        {
            for(int k=0;k<oc_sz && !ret;k++)
                ret |= res[0][(odd_check[k]&1)] && res[1][((odd_check[k]>>1) & 1)] && res[2][((odd_check[k]>>2)&1)] && res[3][((odd_check[k]>>3)&1)];
        }
        if(ret)
            return dp[m][n][!odd] = ret;
    }
    return dp[m][n][!odd] = false;
}
int main()
{
    in_T
    {
        scanf("%d%d", &m, &n);
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                dp[i][j][0] = dp[i][j][1] = -1;
        printf("%d\n", (getans(m,n))?1:2);
    }
}
