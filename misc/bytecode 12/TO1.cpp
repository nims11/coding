/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int m,n,tmp;
    scanf("%d,%d",&m,&n);
    vector< vector<int> > grid(m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            scanf("%d,",&tmp);
            grid[i].push_back(tmp);
        }
        in_I(tmp);grid[i].push_back(tmp);
    }
    vector< vector<int> > ans(m);
    vector< vector<bool> > bur(m+1);
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        ans[i].push_back(-(1<<30));
        bur[i].push_back( grid[i][j]<0?true:false );
    }
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        if(!bur[i][j])
        {
            if(i+1!=m && bur[i+1][j])
            grid[i][j]+=grid[i+1][j];
            if(j+1!=n && bur[i][j+1])
            grid[i][j]+=grid[i][j+1];
            if(i-1!=-1 && bur[i-1][j])
            grid[i][j]+=grid[i-1][j];
            if(j-1!=-1 && bur[i][j-1])
            grid[i][j]+=grid[i][j-1];
            if(j-1!=-1 && i-1!=-1 && bur[i-1][j-1])
            grid[i][j]+=grid[i-1][j-1];
            if(j-1!=-1 && i+1!=m && bur[i+1][j-1])
            grid[i][j]+=grid[i+1][j-1];
            if(j+1!=n && i-1!=-1 && bur[i-1][j+1])
            grid[i][j]+=grid[i-1][j+1];
            if(j+1!=n && i+1!=m && bur[i+1][j+1])
            grid[i][j]+=grid[i+1][j+1];

        }
    }
    for(int i=0;i<m;i++)bur[i].push_back(true);
    for(int i=0;i<=m;i++)bur[m].push_back(true);
    queue <pair<int,int> > BFS;
    BFS.push(make_pair(0,0));
    ans[0][0]=0;
    int foo;
    while(!BFS.empty())
    {
        pair<int,int> k = BFS.front();
        BFS.pop();
        if(!bur[k.first+1][k.second])
        {
            if(ans[k.first][k.second]+grid[k.first+1][k.second] > ans[k.first+1][k.second])
            {
                ans[k.first+1][k.second]=ans[k.first][k.second]+grid[k.first+1][k.second];
                BFS.push(make_pair(k.first+1,k.second));
            }
        }
        if(!bur[k.first][k.second+1])
        {
            if(ans[k.first][k.second]+grid[k.first][k.second+1] > ans[k.first][k.second+1])
            {
                ans[k.first][k.second+1]=ans[k.first][k.second]+grid[k.first][k.second+1];
                BFS.push(make_pair(k.first,k.second+1));
            }
        }
    }
    printf("%d\n",ans[m-1][n-1]);
//    for(int i=0;i<m;i++)
//    {
//        for(int j=0;j<n;j++)
//        printf("%d ",ans[i][j]);
//        newline;
//    }
}
