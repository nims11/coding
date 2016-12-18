/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<stack>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
int n,m,mat[20][20];
bool visited[20]={0};
int ans;
struct foo
{
    int cost,times;
};
foo getans(int S,int cost)
{
    if(S==n)
    {
        foo ans;
        ans.cost=cost;
        ans.times=1;
        return ans;
    }
    foo ans;
    ans.times=0;
    ans.cost=1<<30;
    for(int i=1;i<=n;i++)
    {
        if(mat[S][i]!=-1 && !visited[i])
        {
            visited[i]=true;
            foo k=getans(i,mat[S][i]);
            if(k.cost<ans.cost)
            ans=k;
            else if(k.cost==ans.cost)ans.times+=k.times;
            visited[i]=false;
        }
    }
    ans.cost+=cost;
    return ans;
}
int main()
{
    in_T
    {
        in_I(n);
        in_I(m);
        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        mat[i][j]=-1;

        for(int i=0;i<m;i++)
        {
            int a,b;
            in_I(a);in_I(b);in_I(mat[a][b]);mat[b][a]=mat[a][b];
        }

        ans=0;
        for(int i=0;i<=n;i++)
        visited[i]=0;
        visited[1]=true;
        cout<<getans(1,0).times<<endl;
    }
}
