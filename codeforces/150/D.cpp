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
#include<cmath>
#include<stack>
#include<utility>
#include<set>
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
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a>b;
}
int n,m,h,t;
set<int> neigh[100000];
    set<int>::iterator it1, it2, it;
void print_sol(int u, int v)
{
    cout<<"YES"<<endl;
    cout<<u+1<<" "<<v+1<<endl;
    int H = 0;
    int T = 0;
    for(it1 = neigh[u].begin();it1!=neigh[u].end() && H<h;it1++)
    {
        if(neigh[v].find(*it1)==neigh[v].end())
        {
            H++;
            cout<<*it1 + 1<<" ";
        }
    }
    for(it1 = neigh[v].begin();it1!=neigh[v].end() && T<t;it1++)
    {
        if(neigh[u].find(*it1)==neigh[u].end())
        {
            T++;
            cout<<*it1 + 1<<endl;
        }
    }
}
int common(int u, int v)
{
    int ans = 0;
    for(it1 = neigh[u].begin();it1!=neigh[u].end();it1++)
    {
        if(neigh[v].find(*it1)!=neigh[v].end())
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    cin>>n>>m>>h>>t;
    int x,y;
    int in_deg[n];
    for(int i=0;i<n;i++)
        in_deg[i] = 0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        x--,y--;
        neigh[x].insert(y);
        neigh[y].insert(x);
        in_deg[x]++;
        in_deg[y]++;
    }
    for(int i=0;i<n;i++)
    {
        if(in_deg[i]>h)
        for(it = neigh[i].begin(); it!=neigh[i].end(); it++)
        {
            if(in_deg[*it]>t)
            {
                int foo = common(i, *it);
                if(in_deg[*it] - foo > t && in_deg[i] - foo >h)
                {
                    print_sol(i, *it);
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
