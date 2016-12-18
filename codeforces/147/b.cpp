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
struct cell
{
    int val;
    int x,y;
    friend bool operator<(const cell &a,const cell &b)
    {
        return a.val<b.val;
    }
}tmp;
struct swaps
{
    int x,y,p,q;
}tmp_sw;
int m;
vector<cell> grid;
int main()
{
    cin>>m;
    int c[m];
    for(int i=0;i<m;i++)
    cin>>c[i];
    int tmp2;
    vector<int> qwe[m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<c[i];j++)
        {
            cin>>tmp2;
            qwe[i].push_back(0);
            tmp.val = tmp2;
            tmp.x = i;
            tmp.y = j;
            grid.push_back(tmp);
        }
    }

    pair<int, int> foo[grid.size()];
    sort(grid.begin(),grid.end());
    vector<swaps> ans;
    int curr = 0;
    for(int i=0;i<grid.size();i++)
    {
        qwe[grid[i].x][grid[i].y] = i;
    }
    int lt = max(m,c[0]);
    for(int i=0;i<2*lt;i++)
    {
        int x = 0, y = i;
        for(;x<m && y>=0;x++,y--)
        {
            if(y<c[x])
            foo[curr++] = make_pair(x,y);
        }
    }
//    cout<<"ss"<<endl;
//    for(int i=0;i<grid.size();i++)
//    cout<<i<<" "<<foo[i].first<<"-"<<foo[i].second<<endl;
    for(int i=0;i<grid.size();i++)
    {
        if(grid[i].x != foo[i].first || grid[i].y != foo[i].second)
        {
            tmp_sw.p = grid[i].x+1;
            tmp_sw.q = grid[i].y+1;
            tmp_sw.x = foo[i].first+1;
            tmp_sw.y = foo[i].second+1;
            int to = qwe[foo[i].first][foo[i].second];
            qwe[foo[i].first][foo[i].second] = i;
            qwe[grid[i].x][grid[i].y] = to;
            int qww = grid[to].x;
            grid[to].x = grid[i].x;
            grid[i].x = qww;
            qww = grid[to].y;
            grid[to].y = grid[i].y;
            grid[i].y = qww;
            ans.push_back(tmp_sw);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].p<<" "<<ans[i].q<<" "<<ans[i].x<<" "<<ans[i].y<<endl;
    }
}
