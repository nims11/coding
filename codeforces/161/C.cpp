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

int main()
{
    int n,a,b;
    in_I(n);
    vector<int> adj[n];
    for(int i=0;i<2*n;i++)
    {
        scanf("%d%d", &a,&b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()!=4)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
}
