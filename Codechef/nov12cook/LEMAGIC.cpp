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
int dp[101][101][4][10], n, m, tmp, curr;
char grid[101][101];
int main()
{
    in_T
    {
        in_I(n);
        in_I(m);
        for(int i=0;i<n;i++)
                in_S(grid[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                grid[i][j] -= '0';
        int ans = 0;
        for(int P=0;P<10;P++)
        {
            for(int i=0;i<=n;i++)
                for(int j = 0;j<4;j++)
                    for(int k=0;k<10;k++)
                        dp[i][m][j][k] = 0;
            for(int i=0;i<=m;i++)
                for(int j = 0;j<4;j++)
                    for(int k=0;k<10;k++)
                        dp[n][i][j][k] = 0;
            for(int i=n-1;i>=0;i--)
            {
                for(int j=m-1;j>=0;j--)
                {
                    //CASE 0
                    tmp = 0;
                    curr = grid[i][j];
                    for(int q=0;q<=curr;q++)
                        tmp = max(max(max(dp[i][j+1][0][q], dp[i][j+1][2][q]), max(dp[i+1][j][0][q], dp[i+1][j][1][q])), tmp);
                    for(int q=0;q<10;q++)
                        dp[i][j][0][q] = max(max(dp[i][j+1][0][q], dp[i][j+1][2][q]), max(dp[i+1][j][0][q], dp[i+1][j][1][q]));
                    tmp++;
                    for(int q=curr;q<10;q++)
                        dp[i][j][0][q] = max(tmp, dp[i][j][0][q]);

                    //CASE 1
                    tmp = 0;
                    curr = (grid[i][j]+P)%10;
                    for(int q=0;q<=curr;q++)
                        tmp = max(max(max(dp[i][j+1][1][q], dp[i][j+1][3][q]), max(dp[i+1][j][0][q], dp[i+1][j][1][q])), tmp);
                    for(int q=0;q<10;q++)
                        dp[i][j][1][q] = max(max(dp[i][j+1][1][q], dp[i][j+1][3][q]), max(dp[i+1][j][0][q], dp[i+1][j][1][q]));
                    tmp++;
                    for(int q=curr;q<10;q++)
                        dp[i][j][1][q] = max(tmp, dp[i][j][1][q]);

                    //CASE 2
                    tmp = 0;
                    curr = (grid[i][j]+P)%10;
                    for(int q=0;q<=curr;q++)
                        tmp = max(max(max(dp[i][j+1][0][q], dp[i][j+1][2][q]), max(dp[i+1][j][2][q], dp[i+1][j][3][q])), tmp);
                    for(int q=0;q<10;q++)
                        dp[i][j][2][q] = max(max(dp[i][j+1][0][q], dp[i][j+1][2][q]), max(dp[i+1][j][2][q], dp[i+1][j][3][q]));
                    tmp++;
                    for(int q=curr;q<10;q++)
                        dp[i][j][2][q] = max(tmp, dp[i][j][2][q]);

                    //CASE 3
                    tmp = 0;
                    curr = (curr+P)%10;
                    for(int q=0;q<=curr;q++)
                        tmp = max(max(max(dp[i][j+1][1][q], dp[i][j+1][3][q]), max(dp[i+1][j][2][q], dp[i+1][j][3][q])), tmp);
                    for(int q=0;q<10;q++)
                        dp[i][j][3][q] = max(max(dp[i][j+1][1][q], dp[i][j+1][3][q]), max(dp[i+1][j][2][q], dp[i+1][j][3][q]));
                    tmp++;
                    for(int q=curr;q<10;q++)
                        dp[i][j][3][q] = max(tmp, dp[i][j][3][q]);
                }
            }
            for(int i=0;i<4;i++)
                ans = max(dp[0][0][i][9], ans);
        }
        cout<<ans<<endl;
    }
}
