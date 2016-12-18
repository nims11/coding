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
int x, y;
vector<int> a[301];
bool visited[301];
bool dfs(int idx)
{
//    cout<<idx<<endl;
    visited[idx] = true;
    if(a[idx].size()%2 == 1)
        return false;
    for(int i = 0; i<a[idx].size(); i++)
        if(!visited[a[idx][i]])
            if(!dfs(a[idx][i])) return false;

    return true;
}
int main()
{
    in_T
    {
        int n;
        in_I(n);
        for(int i = 1;i<=300; i++)
            a[i].clear(), visited[i] = false;
        while(1)
        {
            scanf("%d%d", &x, &y);
            if(x == -1)
                break;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        printf(!dfs(n)?"NO\n":"YES\n");
    }
}
