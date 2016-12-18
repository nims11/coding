/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int N;
vector<pair<int, int> > neigh[100010];
long long ecnt[100010];
int dfs(int idx, int par=-1){
    int ret = 1;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i].first;
        if(v == par)continue;
        int id = neigh[idx][i].second;
        int x = dfs(v, idx);
        ret += x;
        ecnt[id] += x*1LL*(N-x);
    }
    return ret;
}
int main()
{
    in_T{
        in_I(N);
        for(int i = 0;i<=N;i++)
            neigh[i].clear(), ecnt[i] = 0;
        int x, y, c;
        long long sum = 0;
        for(int i = 0;i<N-1;i++){
            in_I(x);in_I(y);in_I(c);
            neigh[x].push_back(make_pair(y, i));
            neigh[y].push_back(make_pair(x, i));
            sum += c;
        }
        dfs(1);
        sort(ecnt, ecnt+N-1);
        long long ans = 0;
        long long cur = 1;
        for(int i = N-2;i>=0;i--){
            // cout<<ecnt[i]<<endl;
            if(i == 0){
                cur = sum;
            }
            ans += cur*ecnt[i];
            sum -= cur;
        }
        cout<<ans<<endl;
    }
}
