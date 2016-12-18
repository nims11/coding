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
struct node
{
    int x, y;
    friend bool operator<(node a, node b)
    {
        if(a.x == b.x)
            return a.y<b.y;
        return a.x<b.x;
    }
}tmp;
set<node> coll[100000];
set<node>::iterator it, it2;
int n;
bool solve(int idx)
{
    for(it = coll[idx].begin(); it!=coll[idx].end(); it++)
    {
        if(it->x<tmp.x && it->y<tmp.y)
            return true;
        else if(it->x>=tmp.x)
            break;
    }
    return false;
}
int get_idx()
{
    int start = 0, end = n-1;
    while(start<end)
    {
        int mid = (start+end)/2;
        if(solve(mid))
            start = mid+1;
        else
            end = mid;
    }
    return start;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_I(tmp.x);in_I(tmp.y);
        int idx = get_idx();
//        cout<<idx<<endl;
        coll[idx].insert(tmp);
        it = coll[idx].find(tmp);
        for(++it; it != coll[idx].end(); it++)
        {
            if(tmp.x<it->x && tmp.y<it->y)
            {
                it2 = ++it;
                coll[idx].erase(--it);
                it = it2;
                --it;
            }
        }
    }
    int ans = 0;
    while(!coll[ans].empty())
        ans++;
    printf("%d\n", ans);
}
