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
int v[100001], n;
vector<int> adj[100001];
int res[100001];
int a, b;
struct node
{
    int last[26];
    int max;
    int cnt;
};
node getans(int idx)
{
    node ret;
    for(int i=0;i<26;i++)
        ret.last[i] = 0;
    int maxi = -1, mini = 1000, max2 = -1;
    node last;
    int cnt = 0;
    for(int i=0;i<adj[idx].size();i++)
        if(!v[adj[idx][i]])
    {
        cnt++;
        last = getans(adj[idx][i]);
        if(last.max == -1)
        {
            ret.max = -1;
            return ret;
        }
        if(maxi>last.max)
        {
            max2 = max(max2, last.max);
        }else
        {
            max2 = maxi;
            maxi = last.max;
        }
    }
    if(cnt == 0)
    {
        ret.max = 0;
        res[idx] = 0;
        ret.last[0] = 1;
        ret.cnt = 1;
        return ret;
    }
    if(cnt == 1)
    {
        for(int i=0;i<26;i++)
        {
            int maxx = 0, maxj;
            for(int j=i+1;j<26;j++)
            {
                if(maxx<last.last[j])
                    maxx =last.last[j], maxj = j;
            }
            if(maxj>=last.last[i])
            {
                ret.max = max(last.max, ret.max);
                for(int j=0;j<26;j++)
                    ret.last[i] = last.last[j];
                ret.last[i] = last.cnt+1;
                ret.cnt = last.cnt+1;
                res[idx] = i;
                return ret;
            }
        }
        ret.max = -1;
        return ret;
    }
    res[idx] = max2+1;
    if(res[idx]>=26)
    {
        ret.max = -1;
        return ret;
    }
    ret.max = maxi;
    ret.cnt = 1;
    ret.last[maxi] = 1;
    return ret;
}
int main()
{
    in_I(n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    node ans = getans(1);
    if(ans.max == -1)
        cout<<"Impossible!"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
            printf("%c ", res[i]+'A');
        newline;
    }
}
