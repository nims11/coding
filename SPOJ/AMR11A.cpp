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
bool operator>(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second>b.second;
}
int main()
{
    in_T
    {
        int R,C;
        in_I(R);in_I(C);
        int grid[R][C];
        pair<int, int> dp1[R][C], dp2[R][C];
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
                in_I(grid[i][j]);
        }
        dp1[0][0] = dp2[0][0] = make_pair(grid[0][0], grid[0][0]);
        for(int i=1;i<C;i++)
        {
            dp2[0][i].second = dp2[0][i-1].second + grid[0][i];
            dp2[0][i].first = min(dp2[0][i-1].first, dp2[0][i].second);
            dp1[0][i] = dp2[0][i];
        }
        for(int i=1;i<R;i++)
        {
            dp2[i][0].second = dp2[i-1][0].second + grid[i][0];
            dp2[i][0].first = min(dp2[i-1][0].first, dp2[i][0].second);
            dp1[i][0] = dp2[i][0];
        }
        pair<int, int> tmp1, tmp2;
        for(int i=1;i<R;i++)
        {
            for(int j=1;j<C;j++)
            {
                if(dp2[i][j-1].second>dp2[i-1][j].second)
                {
                    dp2[i][j].second = grid[i][j] + dp2[i][j-1].second;
                    dp2[i][j].first = min(dp2[i][j-1].first, dp2[i][j].second);
                }else
                {
                    dp2[i][j].second = grid[i][j] + dp2[i-1][j].second;
                    dp2[i][j].first = min(dp2[i-1][j].first, dp2[i][j].second);
                }
                dp1[i][j].second = dp1[i-1][j].second + grid[i][j];
                dp1[i][j].first = min(dp1[i-1][j].first, dp1[i][j].second);
                tmp1.second = dp1[i][j-1].second + grid[i][j];
                tmp1.first = min(dp1[i][j-1].first, tmp1.second);
                if(tmp1>dp1[i][j])
                    dp1[i][j]= tmp1;
                tmp1.second = dp2[i][j-1].second + grid[i][j];
                tmp1.first = min(dp2[i][j-1].first, tmp1.second);
                if(tmp1>dp1[i][j])
                    dp1[i][j] = tmp1;
                tmp1.second = dp2[i-1][j].second + grid[i][j];
                tmp1.first = min(dp2[i-1][j].first, tmp1.second);
                if(tmp1>dp1[i][j])
                    dp1[i][j] = tmp1;
            }
        }
        cout<<(-dp1[R-1][C-1].first+1)<<endl;
    }
}
