#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
vector<int> neigh[10001];
int compo[10001];
int compo_cnt;
vector<int> compo_elt[10001];
int c[10001];
void dfs(int idx){
    compo[idx] = compo_cnt;
    compo_elt[compo_cnt].push_back(idx);
    for(int v: neigh[idx]){
        if(!compo[v]){
            dfs(v);
        }
    }
}
int main(){
    int n, m, k;
    in_I(n);
    in_I(m);
    in_I(k);
    for(int i = 0;i<k;i++){
        int x;
        in_I(x);
        c[x] = 1;
    }
    for(int i = 0;i<m;i++){
        int u, v;
        in_I(u);in_I(v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        if(!compo[i]){
            compo_cnt++;
            dfs(i);
        }
    }

    long long ans = 0;

    for(int i = 1;i<=compo_cnt;i++){
        int num_edge = 0;
        for(int u: compo_elt[i]){
            num_edge += neigh[u].size();
        }
        int kk = compo_elt[i].size();
        ans += (kk*(kk-1)/2 - (num_edge)/2);
    }

    vector<int> plebs;
    int total_nodes = 0;
    int largest_c_comp = -1;
    for(int i = 1;i<=compo_cnt;i++){
        bool flag = true;
        for(int u: compo_elt[i]){
            if(c[u]){
                if(largest_c_comp == -1)
                    largest_c_comp = i;
                else if(compo_elt[largest_c_comp].size() < compo_elt[i].size())
                    largest_c_comp = i;
                flag = false;
                break;
            }
        }
        if(flag){
            plebs.push_back(i);
            total_nodes += compo_elt[i].size();
        }
    }
    int pleb_ans = 0;
    for(int x: plebs){
        pleb_ans += (total_nodes - compo_elt[x].size()) * compo_elt[x].size();
    }
    ans += pleb_ans / 2;
    ans += (total_nodes) * compo_elt[largest_c_comp].size();
    cout<<ans<<endl;

}
