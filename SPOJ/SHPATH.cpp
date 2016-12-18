/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<utility>
#include<queue>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int curr,cost;
map<string,int> cities;
vector<pair<int,int> > path[10001];int dist[10001];
int n,p,tmpi,tmpi2,q,src,dest;
char tmp[12];
int main()
{
    in_T
    {
        cities.clear();
        in_I(n);
        for(int i=0;i<n;i++)
        {
            path[i].clear();
            in_S(tmp);
            cities[tmp]=i;
            in_I(p);
            for(int j=0;j<p;j++)
            {
                in_I(tmpi);
                in_I(tmpi2);
                path[i].push_back(make_pair(tmpi-1,tmpi2));
            }
        }
        in_I(q);
        while(q--)
        {
            in_S(tmp);src=cities[tmp];
            in_S(tmp);dest=cities[tmp];
            for(int i=0;i<n;i++)
            dist[i]=1<<30;

            dist[src]=0;
            priority_queue< pair<int,int> > foo;
            foo.push(make_pair(0,src));
            while(!foo.empty())
            {
                pair <int,int> bar=foo.top();
                foo.pop();
                cost=-bar.first;
                curr=bar.second;
                if(dist[curr]<cost)continue;
                if(curr==dest)break;
                for(int i=0;i<path[curr].size();i++)
                {
                    pair <int,int> x=path[curr][i];
                    if(cost+x.second<dist[x.first])
                    {
                        dist[x.first]=cost+x.second;
                        foo.push(make_pair(-dist[x.first],x.first));
                    }
                }
            }
            printf("%d\n",dist[dest]);
        }
    }
}
