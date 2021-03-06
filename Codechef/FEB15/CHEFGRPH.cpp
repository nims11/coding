/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
struct edge{
    long long l1, l2;int  v1, v2;
};
struct evt{
    int type; // 0 -> fw edge, 1 -> bw edge
    int edge_idx;
};
vector<evt> events;
vector<edge> E;
map<pair<long long, int>, int> cache;
const int mod = 1000000007;
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
bool cmpevt(const evt &a, const evt &b){
    long long l1 = (a.type == 0?E[a.edge_idx].l1:E[a.edge_idx].l2);
    int v1 = (a.type == 0?E[a.edge_idx].v1:E[a.edge_idx].v2);
    long long l2 = (b.type == 0?E[b.edge_idx].l1:E[b.edge_idx].l2);
    int v2 = (b.type == 0?E[b.edge_idx].v1:E[b.edge_idx].v2);
    if(l1 != l2)
        return l1 < l2;
    if(v1 != v2)
        return v1 < v2;
    return a.type > b.type;
}
int main()
{
    long long n, m, k;
    in_L(n);
    in_L(m);
    in_L(k);
    long long e0, e1, e2, e3;
    edge e;
    evt ee;

    for(int i = 0;i<k;i++){
        in_L(e0);in_L(e1);in_L(e2);in_L(e3);
        e.l1 = e0, e.l2 = e2, e.v1 = e1, e.v2 = e3;
        E.push_back(e);
        ee.type = 0;
        ee.edge_idx = E.size()-1;
        events.push_back(ee);
        ee.type = 1;
        events.push_back(ee);
    }
    e.l1 = n+1, e.l2 = n+1, e.v1 = 0, e.v2 = 0;
    E.push_back(e);
    ee.type = 0;
    ee.edge_idx = E.size()-1;
    events.push_back(ee);
    sort(events.begin(), events.end(), cmpevt);
    int curWays = 1;
    int tmpCache = 0;
    long long curM = 0;
    int curPrevWays = 1;
    for(int i = 0;i<events.size();i++){
        evt &e = events[i];
        int type = e.type;
        long long l = (type == 0?E[e.edge_idx].l1:E[e.edge_idx].l2);
        int v = (type == 0?E[e.edge_idx].v1:E[e.edge_idx].v2);
        long long l2 = (type == 1?E[e.edge_idx].l1:E[e.edge_idx].l2);
        int v2 = (type == 1?E[e.edge_idx].v1:E[e.edge_idx].v2);
        if(curM < l){
            curWays = (curWays + tmpCache)%mod;
            tmpCache = 0;
            curWays %= mod;
            curPrevWays = (curWays*1LL*POW(m, l-curM-(l==n+1?2:1)))%mod;
            curWays = (curWays*1LL*POW(m, l-curM-(l==n+1?1:0)))%mod;
            curM = l;
        }
        if(type == 0 && !cache.count(make_pair(l, v))){
            cache[make_pair(l, v)] = curPrevWays;
        }else if(type == 1){
            if(!cache.count(make_pair(l, v)))
                cache[make_pair(l, v)] = curPrevWays;
            int tmpInc = cache[make_pair(l2, v2)];
            // cout<<tmpInc<<endl;
            cache[make_pair(l, v)] += tmpInc;
            cache[make_pair(l, v)] %= mod;
            tmpCache += tmpInc;
            tmpCache %= mod;
        }
        // cout<<curM<<" "<<curWays<<endl;
    }
    if(tmpCache)
        curWays = (curWays + tmpCache)%mod;
    printf("%d\n", curWays);
}
