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
int n, adj[400][400];
map<int, vector<int> > sets;
int arr[400];
int compo[400]; 
void dfs(int idx){
    for(int i = 0;i<n;i++){
        if(adj[idx][i] && compo[i] == -1){
            compo[i] = compo[idx];
            dfs(i);
        }
    }
}
bool cmp(int a, int b){
    return arr[a]<arr[b];
}
vector<int> bar[400];
int main()
{
    in_I(n);
    for(int i = 0;i<n;i++){
        in_I(arr[i]);
    }
    char str[400];
    for(int i = 0;i<n;i++){
        in_S(str);
        for(int j = 0;str[j];j++)
            adj[i][j] = str[j]-'0';
        compo[i] = -1;
    }
    for(int i = 0;i<n;i++){
        if(compo[i] == -1){
            compo[i] = i;
            dfs(i);
        }
    }
    for(int i = 0;i<n;i++){
        sets[compo[i]].push_back(arr[i]);
        bar[compo[i]].push_back(i);
    }
    map<int, vector<int> >::iterator it;
    for(it = sets.begin(); it != sets.end(); it++){
        sort(it->second.begin(), it->second.end());
        for(int i = 0;i<it->second.size();i++){
            arr[bar[it->first][i]] = it->second[i];
        }
    }
    for(int i = 0;i<n;i++)
        printf("%d ", arr[i]);
    newline;
}
