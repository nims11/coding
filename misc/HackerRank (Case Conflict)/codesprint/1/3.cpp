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
int N, K;
int grid[20][10];
int dp[20][10][1<<10];
int getans(int gangsta, int merc, int mask){
    mask |= 1<<merc;
    if(gangsta == N)
        return 0;
    int & ans = dp[gangsta][merc][mask];
    if(ans != -1)
        return ans;
    ans = 1e9;
    for(int i = 0;i<K;i++){
        if(i == merc || (mask&(1<<i)) == 0)
            ans = min(ans, getans(gangsta+1, i, mask|(1<<i)));
    }
    ans+=grid[gangsta][merc];
    return ans;
}
int main()
{
    in_I(N);
    in_I(K);
    for(int i = 0;i<N;i++)
        for(int j = 0;j<K;j++)
            for(int k = 0;k<(1<<K);k++)
                dp[i][j][k] = -1;
    for(int i = 0;i<K;i++)
        for(int j = 0;j<N;j++)
            in_I(grid[j][i]);
    int ans = 1e9;;
    for(int i = 0;i<K;i++)
        ans = min(getans(0, i, 0), ans);
    cout<<ans<<endl;
}
