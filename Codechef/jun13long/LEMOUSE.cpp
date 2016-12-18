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
#define TEST(r, c) ((r)>=0 && (r)<n && (c)>=0 && (c)<m && A[r][c] == '1')
using namespace std;
char A[101][103];
int ans[101][101][2];
int n,m;
const int INF = 1000000000;
int main()
{
    in_T
    {
        in_I(n);
        in_I(m);
        for(int i=0;i<n;i++)
        {
            in_S(A[i]);
//            cout<<A[i]<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // from top
                ans[i][j][0] = INF;
                if(i-1>=0)
                    ans[i][j][0] = min(ans[i-1][j][0] + TEST(i, j-1), ans[i-1][j][1]);

                // from bot
                ans[i][j][1] = INF;
                if(j-1>=0)
                    ans[i][j][1] = min(ans[i][j-1][1] + TEST(i-1, j), ans[i][j-1][0]);

                if(ans[i][j][0] == INF && ans[i][j][1] == INF)
                    ans[i][j][0] = ans[i][j][1] = TEST(0, 0);
                if(ans[i][j][0] == INF || ans[i][j][1] == INF)
                    ans[i][j][0] = ans[i][j][1] = min(ans[i][j][0], ans[i][j][1]);
                ans[i][j][0] += TEST(i, j+1) + TEST(i+1, j);
                ans[i][j][1] += TEST(i, j+1) + TEST(i+1, j);
//                ans[i][j] = TEST(i, j+1) + TEST(i+1, j) + x;
//                cout<<ans[i][j]<<" ";
            }
//            cout<<endl;
        }
//        cout<<endl;
        printf("%d\n", min(ans[n-1][m-1][0], ans[n-1][m-1][1]));
    }
}
