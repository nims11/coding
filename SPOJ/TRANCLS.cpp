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
int grid[100][100];
const int INF = 10000;
int main()
{
    int c = 0;
    in_T
    {
        c++;
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            grid[i][j] = 0;
        }
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d", &x, &y);
            grid[x][y] = 1;
        }
        int ans = 0;
        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(grid[i][k] == 1 && grid[k][j] == 1 && grid[i][j] == 0)
            {
                grid[i][j] = 1;
                ans++;
            }
        }
        printf("Case #%d: %d\n", c, ans);
    }
}
