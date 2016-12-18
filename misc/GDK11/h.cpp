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
vector<int> child[100010];
int is_par[100010];
long long res = 0;
int BIT[100011];
int query(int idx, int n)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
void update(int idx, int n, int val)
{
    while(idx<=n)
    {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}
int N,K, S, D;
void dfs(int idx){
    // cout<<idx<<endl;
    if(K-idx > 0)
        res += query(K-idx, 100001);
    update(idx, 100001, 1);
    for(int i = 0;i<child[idx].size();i++)
        dfs(child[idx][i]);
    update(idx, 100001, -1);
}
int main()
{
    in_I(N);
    in_I(K);
    for(int i = 0;i<N-1;i++){
        in_I(S);in_I(D);
        child[S].push_back(D);
        is_par[D] = 1;
    }
    int root = -1;
    for(int i = 1;i<=N;i++)
        if(!is_par[i]){
            root = i;
            break;
        }
    dfs(root);
    printf("%lld", res);
}
