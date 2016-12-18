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
const int mod = 1000000007;
vector<int> neigh[100000];
long long D[100001];
int compo[100001];
int dfs(int idx){
    compo[idx] = 1;
    int ret = 1;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i];
        if(!compo[v]){
            ret += dfs(v);
        }
    }
    return ret;
}
int main()
{
    D[0] = 1;
    D[1] = 1;
    for(int i = 2;i<=100000;i++){
        D[i] = D[i-1]*i;
        D[i] %= mod;
    }
    int N, K;
    in_I(N);in_I(K);
    for(int i = 0;i<K;i++){
        int a, b;
        in_I(a);
        in_I(b);
        neigh[a-1].push_back(b-1);
        neigh[b-1].push_back(a-1);
    }
    long long res = 1;
    for(int i = 0;i<N;i++){
        if(!compo[i]){
            res = (res * (D[dfs(i)]))%mod;
        }
    }
    cout<<res<<endl;
}
