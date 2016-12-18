/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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
int mod = 1000000007;
int n;
vector<pair<int,int> > neigh[100000];
    int visited[100000];
int DFS(int node, int dist)
{
    visited[node]=1;
    int ans =dist;
    int foo[neigh[node].size()];
    int cn=0;
    for(int i=0;i<neigh[node].size();i++)
    {
        if(!visited[neigh[node][i].first]){
        visited[neigh[node][i].first]=1;
        foo[cn++] = DFS(neigh[node][i].first,neigh[node][i].second);
        }
    }
    if(cn==1)
    ans = (ans+ foo[0])%mod;
    for(int i=0;i<cn;i++)
    {
        for(int j=0;j<cn;j++)
            if(j!=i)
                ans = (ans+(foo[j]*(long long)foo[i])%mod)%mod;
    }
//    cout<<ans<<endl;

    for(int i=0;i<cn;i++)
    {
        ans = (ans + (dist*(long long)foo[i])%mod)%mod;
    }
//    cout<<ans<<endl;
    return ans;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
        visited[i]=0;
    int a,b,c;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        neigh[a-1].push_back(make_pair(b-1,c));
        neigh[b-1].push_back(make_pair(a-1,c));
    }
    cout<<DFS(0,0)<<endl;

}
