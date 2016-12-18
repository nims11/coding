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
vector<int> neigh[100001];
int id[100001];
void dfs(int idx){
    for(int i = 0;i<neigh[idx].size();i++){
        int v  = neigh[idx][i];
        if(!id[v]){
            id[v] = id[idx]+1;
            dfs(v);
        }
    }
}
int d;
int dfs3(int idx, int par=-1){
    if(id[idx] == 2){

    }
    int max1 = -1, max2 = -1; 
    for(int i = 0;i<neigh[idx].size();i++){
        int v  = neigh[idx][i];
        if(v !=par){
            int ret = dfs3(v, idx);
            if(ret == -1)
                return -1;
            if(ret > max1)
                max2 = max1, max1 = ret;
            else if(ret > max2)
                max2 = ret;
        }
    }
    if(max1 + max2 == d)return -1;
    return max(0, max1);
}
int dfs2(int idx, int par=-1){
    int ret = 0;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i];
        if(v != par){
            id[v] = id[idx]+1;
            ret = max(ret, dfs2(v, idx)+1);
        }
    }
    return ret;
}
int main()
{
    in_T{
        int n;
        in_I(n);
        for(int i = 0;i<=n;i++)
            neigh[i].clear(), id[i] = 0;
        for(int i = 0;i<n-1;i++){
            int x, y;
            in_I(x);in_I(y);
            neigh[x].push_back(y);
            neigh[y].push_back(x);
        }
        id[1] = 1;
        dfs(1);
        int maxi = 1;
        for(int i = 1;i<=n;i++){
            if(id[maxi] < id[i])
                maxi = i;
        }
        id[maxi] = 0;
        d = dfs2(maxi);
        if(dfs3(maxi) != -1 && d > 1){
            printf("YES\n");
        }else
            printf("NO\n");
    }
}
