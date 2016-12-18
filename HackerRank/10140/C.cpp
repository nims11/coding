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
int n, m;
vector<int> neigh[100010];
int p[100010];
int p2[100010];
int in_order[100010];
int in_order2[100010];
set<int> pq;
int main(){
    in_I(n);in_I(m);
    for(int i = 0;i<m;i++){
        int u, v;
        in_I(u);in_I(v);
        neigh[u].push_back(v);
        in_order[v]++;
        in_order2[v]++;
    }
    for(int i = 0;i<n;i++)
        in_I(p[i]);

    for(int i = 1;i<=n;i++)
        if(in_order[i] == 0)
            pq.insert(i);
    int idx = 0;
    int last_chance = -1;
    while(idx < n){
        auto it = pq.find(p[idx]);
        if(next(it) != pq.end()){
            last_chance = idx;
        }
        int u = *it;
        pq.erase(it);
        for(int v: neigh[u]){
            in_order[v]--;
            if(in_order[v] == 0)
                pq.insert(v);
        }
        idx++;
    }
    if(last_chance == -1){
        printf("-1\n");
        return 0;
    }

    pq.clear();
    {
        for(int i = 1;i<=n;i++)
            if(in_order2[i] == 0)
                pq.insert(i);
        int idx = 0;
        while(idx < n){
            auto it = pq.begin();
            if(idx <= last_chance)
                it = pq.find(p[idx]);
            if(idx == last_chance){
                it = next(it);
            }
            int u = *it;
            p2[idx] = u;
            pq.erase(it);
            for(int v: neigh[u]){
                in_order2[v]--;
                if(in_order2[v] == 0)
                    pq.insert(v);
            }
            idx++;
        }
    }
    for(int i = 0;i<n;i++)
        printf("%d ", p2[i]);
    printf("\n");
}
