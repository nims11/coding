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
vector<int> fwd[10010], bwd[10010];

int N,M,X,Y;
int Index;
int idxes[10010];
int lowlink[10010];
int cnt = 0;
vector<int> comp[10010];
long long res[10010];
const int mod = 1000000000;
stack<int> S;
bool visited[10010];
void strcon(int i){
//    cout<<" "<<i<<endl;
    idxes[i] = lowlink[i] = Index++;
    S.push(i);
    visited[i] = true;

    for(int j = 0;j<fwd[i].size();j++){
        int w = fwd[i][j];
        if(idxes[w] == -1){
            strcon(w);
            lowlink[i] = min(lowlink[i], lowlink[w]);
        }else if(visited[w]){
            lowlink[i] = min(lowlink[i], idxes[w]);
        }
    }
    if(lowlink[i] == idxes[i]){
        int tmp;
        do{
            tmp = S.top();
            S.pop();
            visited[tmp] = false;
//            cout<<tmp<<" ";
            comp[cnt].push_back(tmp);
        }while(tmp != i);
        cnt++;
//        newline;
    }
}
void tarjan(){
    Index = 0;
    cnt = 0;
    for(int i =1;i<=N;i++)
        if(idxes[i] == -1)
        strcon(i);
    for(int i = 1;i<=N;i++)
        visited[i]  = 0;
}
int getans(int idx){
//    cout<<" "<<idx<<endl;
    if(res[idx] != -2){
        return res[idx];
    }
    long long &ret = res[idx];
    ret = 0;
    for(int i = 0;i<bwd[idx].size();i++){
        int cur = getans(bwd[idx][i]);
        if(cur == -1)
            return (ret=-1);
        ret = (ret+cur)%mod;
    }
    return ret;
}
int main()
{
    in_T{
        in_I(N);
        for(int i = 1;i<=N;i++)
            fwd[i].clear(),idxes[i]=-1, comp[i].clear(), bwd[i].clear(),res[i] = -2;
        in_I(M);
        for(int i = 0;i<M;i++){
                in_I(X);in_I(Y);
            fwd[X].push_back(Y);
            bwd[Y].push_back(X);
        }
        tarjan();
        queue<int> BFS;
        for(int i = 0;i<cnt;i++){
            if(comp[i].size()>1){
                for(int j = 0;j<comp[i].size();j++)
                {
//                    cout<<comp[i][j]<<" ";
                    res[comp[i][j]] = -1;
                }
//                newline;
            }
        }
        BFS.push(1);
        while(!BFS.empty()){
            int x = BFS.front();
            BFS.pop();
            if(res[x] == -1)
                res[x] = -3;
            for(int i = 0;i<fwd[x].size();i++){
                if(res[fwd[x][i]] == -2){
                    if(res[x] == -3)
                        res[fwd[x][i]] = -3;
                    BFS.push(fwd[x][i]);
                }
            }
        }
        for(int i = 1;i<=N;i++)
            if(res[i] == -1)
                res[i] = 0;
            else if(res[i] == -3)
                res[i] = -1;

        if(res[N] == -1){
            printf("INFINITE PATHS\n");
            continue;
        }else if(res[1] == -1 || res[N] == 0){
            printf("0\n");
            continue;
        }
        res[1] = 1;
        int ans = getans(N);
        if(ans == -1){
            printf("INFINITE PATHS\n");
        }else
            printf("%d\n", ans);
//        queue<pair<int, int> > BFS2;
//        BFS.push(make_pair(1, 1));
//        res[1] = 1;
//        while(!BFS.empty()){
//            int x = BFS.front();
//            BFS.pop();
//            for(int i = 0;i<fwd[x].size();i++){
//                if(res[fwd[x][i]] != -1){
//                    res[fwd[x][i]] =
//                }
//            }
//        }
    }
}
