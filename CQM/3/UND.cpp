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
int u,d,k,x;
int dp[51][51][2];
const int INF = 1e9;
bool is_valid(int i, int j, int u, int d)
{
    if(i == 0 && j == 0)
        return false;
    if(i>u || j>d)
        return false;
    if(i<j && i!=0)
        return false;
    if(u-i < d-j && u-i != 0)
        return false;
    return true;
}
int getans(int u, int d, int s)
{
//    cout<<u<<" "<<d<<" "<<s<<endl;
    if(u<0 || d<0)
        return INF;
    if(u!=0 && u<d)
        return INF;
    if(::u-u !=0 && ::u-u< ::d-d)
        return INF;
    if(dp[u][d][s] != INF)
        return dp[u][d][s];
    int &ret = dp[u][d][s];
    ret--;
    if(s == 1)
    {
        for(int i = 0; i<=k; i++)
            for(int j = 0; j<=k-i;j++)
        {
//            cout<<u<<" "<<d<<" "<<s<<"-> "<<i<<" "<<j<<" "<<u<<" "<<d<<" "<<is_valid(i, j, u, d)<<endl;
//            if(is_valid(i, j, u, d) && !((::u-u+i)<(::d-d+j) && (::u-u+i) != 0) && u-i != ub && d-j != db)
//                cout<<u<<" "<<d<<" "<<s<<"-> "<<u-i<<" "<<d-j<<" "<<0<<endl;
                ret = min(ret, 1+getans(u-i, d-j, 0));
        }
    }else
    {
        for(int i = 0; i<=k; i++)
            for(int j = 0; j<=k-i;j++)
            {
//                if(is_valid(i, j, ::u-u, ::d-d) && !((u+i)<(d+j) && u+i != 0) && u+i != ub && d+j != db)
//                    cout<<u<<" "<<d<<" "<<s<<"-> "<<u+i<<" "<<d+j<<" "<<1<<endl;
                    ret = min(ret, 1+getans(u+i, d+j, 1));
            }
    }
    return ret;
}
int main()
{
    in_T
    {
        scanf("%d%d%d%d", &u, &d, &k, &x);
        for(int i = 0; i<=u; i++)
            for(int j = 0; j<=d; j++)
            dp[i][j][0] = dp[i][j][1] = INF;
        dp[u][d][1] = 0;
        getans(0, 0, 0);
        printf("%d\n", dp[0][0][0] >= INF-5?-1:dp[0][0][0]*x);
    }
}
