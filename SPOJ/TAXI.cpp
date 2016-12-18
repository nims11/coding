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
int p, tt, s, c;
pair<int, int> P[401], T[201];
int main()
{
    in_T{
        scanf("%d%d%d%d", &p, &tt, &s, &c);
        neigh.clear();
        for(int i = 0; i<p;i++){
            in_I(P[i].first);
            in_I(P[i].second);
            neigh.push_back(vector<int>());
        }
        long long maxi = s*1LL*c;
        for(int i = 0; i<tt;i++){
            in_I(T[i].first);
            in_I(T[i].second);
            neigh.push_back(vector<int>());
            for(int j = 0;j<p;j++){
                if((abs(T[i].first-P[j].first)+abs(T[i].second-P[j].second))*200LL <= maxi)
                    neigh[neigh.size()-1].push_back(j);
            }
        }
        for(int i = 0;i<neigh.size();i++)
            bw[i] = -1;
        printf("%d\n", max_flow());
    }
}
