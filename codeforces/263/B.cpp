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
vector<int> neigh[100001];
int color[100001];
int latest = 0;
int MOD = 1000000007;
int mod = 1000000007;
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}

struct dfsInfo{
    long long cur, tot, invSum, prevMult;
    dfsInfo(){
        tot = prevMult = 1;
        cur = 0;
        invSum = 0;
    }
};
int inv(int n){
    return POW(n, MOD-2);
}
dfsInfo dfs(int idx, int par = -1){
    if(color[idx] == 1){
        dfsInfo ret;
        for(int i = 0;i<neigh[idx].size(); i++){
            int v = neigh[idx][i];
            if(v != par){
                dfsInfo tmp = dfs(v, idx);
                if(tmp.prevMult == -1)
                    continue;
                tmp.cur++;
                tmp.prevMult = (tmp.prevMult * tmp.cur)%MOD;
                tmp.invSum = (tmp.invSum + inv(tmp.cur))%MOD;
                ret.tot = ( ret.tot * ((tmp.prevMult * tmp.invSum)%MOD ))%MOD;
            }
        }
        return ret;
    }else {
        dfsInfo ret;
        ret.prevMult = -1;

            vector<dfsInfo> branches;
        for(int i = 0;i<neigh[idx].size(); i++){
            int v = neigh[idx][i];
            if(v != par){
                dfsInfo tmp = dfs(v, idx);
                if(tmp.prevMult == -1)
                    continue;
                tmp.cur++;
                branches.push_back(tmp);
            }
        }
        if(branches.size()>0){
            ret.prevMult = 1;
            if(branches.size() == 1){
                return branches[0];
            }
            for(int i = 0;i<branches.size();i++){
                ret.prevMult = (ret.tot * branches[i].cur)%MOD;
                ret.invSum = (ret.invSum + inv(branches[i].cur))%MOD;
                branches[i].tot = (branches[i].tot + branches[i].invSum * branches[i].prevMult) % MOD;
            }
            for(int i = 0;i<branches.size();i++){
                ret.tot = (ret.tot * ((branches[i].cur*branches[i].tot)%MOD) )%MOD;
            }
            ret.cur = 0;
        }
        return ret;
    }
}
long long with[100001], without[100001];
void dfs2(int idx, int parent = -1){
    if(color[idx]){
        without[idx] = 0;
        with[idx] = 1;
        for(int i = 0;i<neigh[idx].size();i++){
            if(neigh[idx][i] != parent){
                dfs2(neigh[idx][i], idx);
                with[idx] = (with[idx] * (without[neigh[idx][i]] + with[neigh[idx][i]]))%MOD;
            }
        }
    }else{
        without[idx] = 1;
        with[idx] = 0;
        long long withoutProd = 1;
        for(int i = 0;i<neigh[idx].size();i++)
            if(neigh[idx][i] != parent){
                dfs2(neigh[idx][i], idx);
                withoutProd = (withoutProd * (without[neigh[idx][i]] + with[neigh[idx][i]]))%MOD;
            }

        for(int i = 0;i<neigh[idx].size();i++){
            if(neigh[idx][i] != parent){
                without[idx] = (without[idx] * (with[neigh[idx][i]]+without[neigh[idx][i]]))%MOD;
                with[idx] = (with[idx] + with[neigh[idx][i]]*
                        ((withoutProd * POW(without[neigh[idx][i]]+with[neigh[idx][i]], MOD-2))%MOD))
                    %MOD;
            }
        }
    }
}
int main()
{
    int n, x;
    in_I(n);
    for(int i = 0;i<n-1;i++){
        in_I(x);
        neigh[i+1].push_back(x);
        neigh[x].push_back(i+1);
    }
    for(int i = 0;i<n;i++){
        in_I(x);
        color[i] = x;
        if(x == 1)
            latest = i;
    }
    dfs2(latest);
    printf("%d\n", with[latest]);
}
