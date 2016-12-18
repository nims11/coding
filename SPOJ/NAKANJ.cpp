/*
    Nimesh Ghelani (nims11)
    Floyd Warshall
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
#define INF 1000000000
using namespace std;
int dp[64][64];
int dx[8] ={1, 2,  2,  1, -1, -2, -2, -1};
int dy[8] ={2, 1, -1, -2, -2, -1,  1,  2};
int main()
{
    for(int i=0;i<64;i++)
        for(int j=0;j<64;j++)
        {
            dp[i][j] = INF;
        }
    for(int i=0;i<64;i++)
        dp[i][i] = 0;
    for(int i=0;i<64;i++)
    {
        int xx = i/8;
        int yy = i%8;
        for(int k=0;k<8;k++)
        {
            int x = xx+dx[k], y = yy+dy[k];
            if(x>=0 && x<8 && y>=0 && y<8)
            {
                dp[x*8+y][xx*8+yy] = dp[xx*8+yy][x*8+y] = 1;
            }
        }
    }
    for(int k=0;k<64;k++)
    {
        for(int i=0;i<64;i++)
            for(int j=0;j<64;j++)
        {
            dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
        }
    }
    char str1[4], str2[4];
    in_T
    {
        in_S(str1);
        in_S(str2);
        printf("%d\n", dp[(str1[0]-'a')*8+str1[1]-'1'][(str2[0]-'a')*8+str2[1]-'1']);
    }
}
