/*
ID: nimeshg1
PROG: castle
LANG: C++
*/
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
#include<set>
#include<utility>
#include<fstream>
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
ifstream fin("castle.in");
ofstream fout("castle.out");
#define cin fin
#define cout fout
int comps = 0;
int comp_size[3000];
int m,n;
struct node
{
    int walls;
    int component;
    int visited;
} nodes[51][51];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
void dfs(int i, int j)
{
////    cout<<i+1<<" "<<j+1<<endl;
    nodes[i][j].visited = 1;
    nodes[i][j].component = comps;
    comp_size[comps]++;
    for(int a=0;a<4;a++)
    {
        int x = i+dy[a];
        int y = j+dx[a];
        if(!(nodes[i][j].walls & (1<<a)) && !nodes[x][y].visited)
        {
            dfs(x,y);
        }
    }
}
int max_comp_size = 0;
int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {cin>>nodes[i][j].walls;nodes[i][j].component = -1;nodes[i][j].visited=0;}

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!nodes[i][j].visited)
            {
                dfs(i, j);
                max_comp_size = max(max_comp_size, comp_size[comps]);
                comps++;
            }
        }
    }

    cout<<comps<<endl;
    cout<<max_comp_size<<endl;

    int max_size = 0;
    pair<int, int> res;
    char dir;

    for(int j=0;j<m;j++)
    for(int i=n-1;i>=0;i--)
    {
        // N
        if((nodes[i][j].walls  & (1<<1)))
        {
            if(i!=0 && nodes[i-1][j].component != nodes[i][j].component)
            {
                if(comp_size[nodes[i-1][j].component] + comp_size[nodes[i][j].component]>max_size)
                {
                    max_size = comp_size[nodes[i-1][j].component] + comp_size[nodes[i][j].component];
                    res.first = i+1;
                    res.second = j+1;
                    dir = 'N';
                }
            }
        }

        // E
        if((nodes[i][j].walls  & (1<<2)))
        {
            if(j+1!=m && nodes[i][j+1].component != nodes[i][j].component)
            {
                if(comp_size[nodes[i][j+1].component] + comp_size[nodes[i][j].component]>max_size)
                {
                    max_size = comp_size[nodes[i][j+1].component] + comp_size[nodes[i][j].component];
                    res.first = i+1;
                    res.second = j+1;
                    dir = 'E';
                }
            }
        }
    }
    cout<<max_size<<endl;
    cout<<res.first<<" "<<res.second<<" "<<dir<<endl;
}
