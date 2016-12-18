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
vector<vector<int> > neigh;
int bw[100000]; // all -1s
int vis[100000];
int find_path(int n){
    if(vis[n])
        return 0;
    vis[n] = 1;
    for(int i = 0;i<neigh[n].size();i++)
        if(bw[neigh[n][i]] == -1 || find_path(bw[neigh[n][i]])){
            bw[neigh[n][i]] = n;
            return 1;
        }
    return 0;
}
int max_flow(){
    int res = 0;
    for(int i = 0;i<neigh.size();i++){
        if(neigh[i].size() == 0)
            continue;
        memset(vis, 0, sizeof(int)*neigh.size());
        res += find_path(i);
    }
    return res;
}

int main(){
    int t, z;
    cin>>t;
    for(z = 1;z<=t;z++){
        int n;
        cin>>n;
        vector<string> topics[2];
        map<string, int> tmp1, tmp2;
        int cnt = 0;
        neigh.clear();
        for(int i = 0;i<2*n;i++)
            neigh.push_back(vector<int>());
        for(int i = 0;i<n;i++){
            string s1, s2;
            cin>>s1>>s2;
            if(tmp1.find(s1) == tmp1.end())
                tmp1[s1] = cnt++;
            if(tmp2.find(s2) == tmp2.end())
                tmp2[s2] = cnt++;
            neigh[tmp1[s1]].push_back(tmp2[s2]);
            neigh[tmp2[s2]].push_back(tmp1[s1]);
        }
        for(int i = 0;i<=cnt;i++)
            bw[i] = -1;
        int res = max_flow()/2;
        if(res*2 < cnt)
            res += (cnt - res*2);
        res = max(0, n-res);
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}
