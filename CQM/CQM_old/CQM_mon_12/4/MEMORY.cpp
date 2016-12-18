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
    in_T
    {
        int n,e;
        in_I(n);in_I(e);
        int link[301][301];
        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        link[i][j]=-1;
        int a,b,c;
        for(int i=0;i<e;i++)
        {
            in_I(a);in_I(b);in_I(c);
            link[a][b]=link[b][a]=c;
        }
        int mina = 1<<30;
        for(int i=1;i<=n;i++)
        {
            int start[301],end[301];
            for(int j=0;j<=n;j++)start[j]=end[j]=-1;
            start[i]=0;
            end[i]=0;
            priority_queue<pair<int,int> > BFS;
            BFS.push(make_pair(0,i));
            while(!BFS.empty())
            {
                pair <int,int> foo = BFS.top();
                foo.first = -foo.first;
                BFS.pop();
                if(i==1)
                cout<<foo.first<<" "<<foo.second<<endl;
                for(int j=1;j<=n;j++)
                {
                    if(j!=foo.second && link[foo.second][j]!=-1)
                    {
                        if(start[j]==-1)
                        {
                            start[j]=end[j]=link[foo.second][j]+foo.first;
                            BFS.push(make_pair(-link[foo.second][j]-foo.first,foo.second));
                        }else
                        {
                            if(end[j]<link[foo.second][j]+foo.second)
                            {
                                end[j] = link[foo.second][j]+foo.second;
                                BFS.push(make_pair(-link[foo.second][j]-foo.first,foo.second));
                            }
                        }
                    }
                }
            }
            int aaa=0;
            for(int i=1;i<=n;i++)
            aaa += end[i]-start[i];
            mina = min(mina,aaa);
        }
        cout<<mina<<endl;
    }
}
