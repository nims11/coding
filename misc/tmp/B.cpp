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
FILE *fin = fopen("beloved.in", "r");
FILE *fout = fopen("beloved.out", "w");
int main()
{
    int N;
    fscanf(fin, "%d", &N);
    int P[N+1];
    P[0] = 0;
    for(int i = 1;i<=N;i++)
        fscanf(fin, "%d", &P[i]);
    int dp[N+1][N+1], cost[N+1][N+1];
    pair<int, int> bktrack[N+1][N+1], prevDP[N+1][N+1];
    for(int i = 0;i<=N;i++)for(int j = 0;j<=N;j++)
        dp[i][j] = 0, cost[i][j] = 0, bktrack[i][j] = make_pair(0, 0), prevDP[i][j] = make_pair(0, 0);
    for(int i = 1;i<=N;i++){
        int K, X;
        fscanf(fin, "%d", &K);
        while(K--){
            fscanf(fin, "%d", &X);
            cost[i][X] = P[i]*P[i];
        }
    }
    for(int i = 1;i<=N;i++)
        for(int j = 1;j<=N;j++){
            pair<int, int> prevMx = prevDP[i-1][j-1];
            dp[i][j] = cost[i][j] + dp[prevMx.first][prevMx.second];
            bktrack[i][j] = prevMx;
            pair<int, int> c1 = make_pair(i, j), c2 = prevDP[i-1][j], c3 = prevDP[i][j-1];
            int r1 = dp[c1.first][c1.second], r2 = dp[c2.first][c2.second], r3 = dp[c3.first][c3.second];
            if(r1 > max(r2, r3))
                prevDP[i][j] = c1;
            else if(r2 > max(r1, r3))
                prevDP[i][j] = c2;
            else
                prevDP[i][j] = c3;
        }
    int res[N+1];
    for(int i = 0;i<=N;i++)
        res[i] = 0;
    pair<int, int> cur = prevDP[N][N];
    while(cur.first != 0){
        res[cur.first] = cur.second;
        cur = bktrack[cur.first][cur.second];
    }
    for(int i = 1;i<=N;i++)
        printf("%d ", res[i]);
}
