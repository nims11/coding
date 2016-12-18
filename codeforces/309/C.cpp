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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int vis[100010];
int n, m;
vector<pair<int, int> > neigh[100010];
bool make_set(int idx, int mode = 1){
    vis[idx] = mode;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i].first;
        int c = neigh[idx][i].second;
        if(c == 1){
            if(vis[v] && vis[v] != mode)
                return false;
            else if(!vis[v]){
                bool ret = make_set(v, mode);
                if(!ret)return false;
            }
        }else{
            if(vis[v] && vis[v] == mode){
                return false;
            }else if(!vis[v]){
                bool ret = make_set(v, -mode);
                if(!ret)return false;
            }
        }
    }
    return true;
}
int main()
{
    in_I(n);
    in_I(m);
    int x, y, c;
    for(int i = 0;i<m;i++){
        in_I(x);in_I(y);in_I(c);
        neigh[x].push_back({y, c});
        neigh[y].push_back({x, c});
    }
    int num_set = 0;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            num_set++;
            if(!make_set(i)){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    long long res = 1;
    for(int i = 1;i<num_set;i++){
        res = MUL(res, 2);
    }
    cout<<res<<endl;
}
