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
#include<climits>
using namespace std;
int m,n,k;
const long long unsigned INF = -1;
struct node
{
    int l, r, c, sz;
    friend bool operator<(const node &a, const node &b)
    {
        return a.r<b.r;
    }
}nodes[100005];
long long unsigned dp[301][301];
vector<int> ending[301];;
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        dp[i][j] = INF;
    for(int i=0;i<m;i++)
    {
        cin>>nodes[i].l>>nodes[i].r>>nodes[i].c;
        ending[nodes[i].r].push_back(i);
        nodes[i].sz = nodes[i].r-nodes[i].l+1;
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++)
        dp[0][i] = INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j] = dp[i-1][j];
            for(int k=0;k<ending[i].size();k++)
            {
//                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//                cout<<i-nodes[ending[i][k]].sz<<" "<<j-nodes[ending[i][k]].sz<<endl;
                if(nodes[ending[i][k]].sz<=j && dp[i-nodes[ending[i][k]].sz][j-nodes[ending[i][k]].sz] != INF)
                {
                    dp[i][j] = min(dp[i][j], nodes[ending[i][k]].c + dp[i-nodes[ending[i][k]].sz][j-nodes[ending[i][k]].sz]);
                }
            }
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    long long unsigned ans = INF;
    for(int i=k;i<=n;i++)
    {
        ans = min(ans, dp[n][i]);
    }
    if(ans != INF)
    {
        cout<<ans<<endl;
    }else
    cout<<-1<<endl;
}
