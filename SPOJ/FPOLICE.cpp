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
int risk[100][100], Time[100][100];
int N,T;
int dp[100][251];
int main()
{
    in_T
    {
        in_I(N);in_I(T);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                in_I(Time[i][j]);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                in_I(risk[i][j]);
        for(int i=0;i<N;i++)
            for(int j=0;j<=T;j++)
                dp[i][j] = 2000000000;

        queue<pair<int, pair<int, int> > > BFS; // station, Time, risk
        BFS.push(make_pair(0, make_pair(0,0)));
        while(!BFS.empty())
        {
            pair<int, pair<int, int> > X = BFS.front();
            BFS.pop();
            for(int i=0;i<N;i++)
            {
                if(i!=X.first && X.second.first+Time[X.first][i]<=T && dp[i][X.second.first+Time[X.first][i]]>X.second.second+risk[X.first][i])
                {
                    for(int j=X.second.first+Time[X.first][i]; j<=T && dp[i][j] > X.second.second+risk[X.first][i]; j++)
                        dp[i][j] = X.second.second+risk[X.first][i];
                    BFS.push(make_pair(i, make_pair(X.second.first+Time[X.first][i], X.second.second+risk[X.first][i])));
                }
            }
        }
        if(dp[N-1][T] == 2000000000)
        {
            printf("-1\n");
            continue;
        }
        int ti = T;
        int st = dp[N-1][T];
        while(ti>=0 && st == dp[N-1][ti])ti--;
        ti++;
        printf("%d %d\n", dp[N-1][T], ti);

    }
}
