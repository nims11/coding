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
    in_T
    {
        int n;
        in_I(n);
        int grid[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                in_I(grid[i][j]);
        for(int i=1;i<n;i++)
            grid[0][i] += grid[0][i-1], grid[i][0] += grid[i-1][0];
        for(int i=1;i<n;i++)
            for(int j=1;j<n;j++)
            {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        if(grid[n-1][n-1]<0)printf("Bad Judges\n");
        else
        printf("%.6lf\n", double(grid[n-1][n-1])/(2*n-3));
    }
}
