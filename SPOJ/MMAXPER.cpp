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
int mod(int n)
{
    return n<0?-n:n;
}
int getans(int w, int h, int h_pre)
{
    return w+mod(h-h_pre);
}
int main()
{
    int n;
    in_I(n);
    int dp[n][2];
    int r[n][2];
    for(int i=0;i<n;i++)
    {
        in_I(r[i][0]);
        in_I(r[i][1]);
    }
    dp[0][0] = r[0][0];
    dp[0][1] = r[0][1];
    for(int i=1;i<n;i++)
    {
        //case 1
        dp[i][0] = max(dp[i-1][0]+getans(r[i][0], r[i][1], r[i-1][1]), dp[i-1][1]+getans(r[i][0], r[i][1], r[i-1][0]));

        //case 2
        dp[i][1] = max(dp[i-1][0]+getans(r[i][1], r[i][0], r[i-1][1]), dp[i-1][1]+getans(r[i][1], r[i][0], r[i-1][0]));
    }
    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
}
