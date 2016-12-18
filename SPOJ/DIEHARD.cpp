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
int dp[1005][2005][3];
int getans(int h, int a, int turn)
{
    if(h <= 0 || a <= 0)
        return 0;

    if(dp[h][a][turn])
        return dp[h][a][turn];

    int &ret = dp[h][a][turn];
    ret = 1;
    switch(turn)
    {
    case 0:
        ret += max(getans(h+3, a+2, 1), getans(h+3, a+2, 2));
        break;
    case 1:
        ret += max(getans(h-5, a-10, 0), getans(h-5, a-10, 2));
        break;
    case 2:
        ret += max(getans(h-20, a+5, 0), getans(h-20, a+5, 1));
        break;
    }
    return ret;
}
int main()
{
    in_T
    {
        int h,a;
        in_I(h);
        in_I(a);
        cout<<max(getans(h,a,0), max(getans(h,a,1), getans(h,a,2)))<<endl;
    }
}
