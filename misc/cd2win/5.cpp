#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
set<int> neigh[500];
int cnt = 0;
int B[500];
int in_deg[500];
void dfs(int idx, int par=-1){
    for(int v: neigh[idx]){
        in_deg[v]--;
        if(B[v] == -1)
            B[v] = B[idx]+1;
        else
            B[v] = max(B[v], B[idx]+1);
        if(in_deg[v] == 0)
            dfs(v, idx);
    }
}
int main(){
    int n;
    in_I(n);
    vector<vector<int>> A;
    memset(B, -1, sizeof(B));
    for(int i = 0;i<n;i++){
        A.push_back(vector<int>());
        int cn;
        in_I(cn);
        while(cn--){
            int x;
            in_I(x);
            A[i].push_back(x);
            neigh[i+1].insert(x);
            in_deg[x]++;
        }
    }
    for(int i = 1;i<=n;i++){
        if(in_deg[i] == 0 && B[i] == -1){
            B[i] = 1;
            dfs(i);
        }
    }
    for(int i = 1;i<=n;i++)
        cout<<B[i]<<" ";
    cout<<endl;
}
