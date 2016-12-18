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
int N1, N2, D, ip1, ip2;
vector<int> adj[100001];
int getans(int start)
{
    int ret = 0;
    for(int i=0;i<adj[start].size();i++)
    {
        if((start<=N1 && adj[start][i]>N1) || (start>N1 && adj[start][i]<=N1))
        {
            ret = max(ret, getans(adj[start][i]));
        }else
            ret = max(ret, -1+getans(adj[start][i]));
    }
    return ret+1;
}
int main()
{
    while(1)
    {
        scanf("%d%d%d", &N1, &N2, &D);
        if(!N1)return 0;
        int flag[N1+N2+1];
        for(int i=0;i<=N1+N2;i++)
            flag[i] = 0, adj[i].clear();
        for(int i=0;i<D;i++)
        {
            scanf("%d%d", &ip1, &ip2);
            adj[ip1].push_back(ip2);
            flag[ip2] = 1;
        }
        int ans = 0;
        int prev_start = 0;
        int add = 2;
        for(int i=1;i<=N1+N2;i++)
        {
            if(!flag[i])
            {
                int foo = getans(i) -1;
//                cout<<foo<<endl;
                if(foo==0)
                {
                    if(ans==0)
                    {
                        add = 3;
                    }
                }else
                {
                    if(foo>ans)
                    {
                        ans = foo;
                        add = 2;
                        prev_start = i;
                    }else if(foo==ans)
                        if(add==2)
                            if((prev_start<=N1 && i>N1)||(prev_start>N1 && i<=N1))
                                add = 3;
                }
            }
        }
        cout<<ans+add<<endl;
    }
}
