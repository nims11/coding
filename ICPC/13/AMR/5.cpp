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

const int INF = 1e9;
int grid[301][4];
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define diff3(a, b, c) max3(a, b, c)-min3(a, b, c)
struct node{
    int n, i, j;
};
int n;
const int MAX_ALL = 3;
const int MAXX = 2*MAX_ALL+1;
const int MAX = 300;
bool valid(int n1, int n2, int n3)
{

    if(n1>=0 && n2>=0 && n3>=0 && n1<=MAX && n2 <=MAX && n3<=MAX)
        return true;
    return false;

}
int dp[301][301][301];
int main()
{
    in_T
    {
        in_I(n);
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=3;j++)
                in_I(grid[i][j]);

        for(int i = 0;i<=n;i++)
            for(int j = 0;j<MAXX;j++)
                for(int k = 0;k<MAXX;k++)
                    dp[i][j][k] = INF;
        dp[0][MAX_ALL][MAX_ALL] = 0;
        for(int i = 1;i<=n;i++)
            for(int j = 0;j<MAXX;j++)
                for(int k = 0;k<MAXX;k++)
        {
            int n1 = i, n2 = i+j-MAX_ALL, n3 = n2+k-MAX_ALL;
            if(n1 > n || n2 > n || n3 > n || n1<0 || n2<0 || n3<0)
                continue;
//            if(n1 == 3 && n2 == 3 && n3 == 0)
//                cout<<valid(n1, n2-3, n3).i<<endl;
            //XXX hori
            if(n1 == n2 && n2 == n3)
            {
//                cout<<diff3(grid[n1][1], grid[n1][2], grid[n1][3])<<endl;
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][MAX_ALL][MAX_ALL] + diff3(grid[n1][1], grid[n1][2], grid[n1][3]));
            }

//            XXX verti
            node foo;
            if((foo = valid(n1-3, n2, n3)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n1][1], grid[n1-1][1], grid[n1-2][1]));

            if((foo = valid(n1, n2-3, n3)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n2][2], grid[n2-1][2], grid[n2-2][2]));

            if((foo = valid(n1, n2, n3-3)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n3][3], grid[n3-1][3], grid[n3-2][3]));

            //L1
            if(n2 == n1 && (foo = valid(n1-2, n2-1, n3)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n1][1], grid[n1-1][1], grid[n2][2]));

            if(n2 == n3 && (foo = valid(n1, n2-2, n3-1)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n2][2], grid[n3][3], grid[n2-1][2]));

            //L2
            if(n2 == n1 && (foo = valid(n1-1, n2-2, n3)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n1][1], grid[n2][2], grid[n2-1][2]));

            if(n2 == n3 && (foo = valid(n1, n2-1, n3-2)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n2][2], grid[n3][3], grid[n3-1][3]));

            //L3
            if(n1-n2 == 1 && (foo = valid(n1-2, n2-1, n3)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n1][1], grid[n1-1][1], grid[n2][2]));

            if(n2-n3 == 1 && (foo = valid(n1, n2-2, n3-1)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n2][2], grid[n3][3], grid[n2-1][2]));

            //L4
            if(n2-n1 == 1 && (foo = valid(n1-1, n2-2, n3)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n1][1], grid[n2-1][2], grid[n2][2]));

            if(n3-n2 == 1 && (foo = valid(n1, n2-1, n3-2)).n != -1)
                dp[i][j][k] = min(dp[i][j][k], dp[foo.n][foo.i][foo.j] + diff3(grid[n2][2], grid[n3][3], grid[n3-1][3]));
        }
        for(int i = 0;i<=n;i++)
            for(int j = 0;j<MAXX;j++)
            for(int k = 0;k<MAXX;k++)
            if(j+i-MAX_ALL>=0 && j+i-MAX_ALL+k-MAX_ALL>=0)
                cout<<i<<" "<<j+i-MAX_ALL<<" "<<j+i-MAX_ALL+k-MAX_ALL<<" "<<dp[i][j][k]<<endl;
        printf("%d\n", dp[n][MAX_ALL][MAX_ALL]);
    }
}
