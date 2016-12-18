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
#include<cassert>
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
int n, p, k;
struct node
{
    int idx;
    pair<int, int> x; // (displease, hair)
}nodes[100003];
//bool cmp1(const node &a, const node &b)
//{
//    return a.x<b.x;
//}
bool cmp3 (const node &a, const node &b)
    {
        if(a.x.first == b.x.first)
            return a.x.second>b.x.second;
        return a.x.first<b.x.first;
    }
struct set_compare{
    bool operator() (int a, int b)
    {
        return a>b;
    }
};
struct set_compare2{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b)
    {
        return a>b;
    }
};
//bool cmp2(const node &a, const node &b)
//{
//    if(a.x.second == b.x.second)
//        return a.x.first<b.x.first;
//    return a.x.second<b.x.second;
//}

int main()
{
    cin>>n>>p>>k;
    long long pre_sum[n+1];
    pre_sum[0] = 0;
    for(int i=0;i<n;i++)
    {
        in_I(nodes[i].x.second);
        in_I(nodes[i].x.first);
        nodes[i].idx = i+1;
    }
    sort(nodes, nodes+n, cmp3);
    for(int i=0;i<n;i++)
        pre_sum[i+1] = pre_sum[i] + nodes[i].x.first;
    pair<long long, long long> anss = make_pair(0, 0);
    int pos;
    multiset<int, set_compare> max_k, rest;
    multiset<int, set_compare>::iterator it, it2;
    int cnt;
    long long sum = 0;
    for(int i=p-k+1;i<n;i++)
        rest.insert(nodes[i].x.second);
    for(cnt = 0, it = rest.begin(); cnt < k-1; cnt++)
    {
        max_k.insert(*it);
        sum += *it;
        it2 = it;
        ++it2;
        rest.erase(it);
        it = it2;
    }
    for(int i=p-k+1; i<=n-(k-1); i++)
    {
        pair<long long, long long> loc = make_pair(sum + nodes[i-1].x.second, pre_sum[i-2+1]-pre_sum[i-2-(p-k)+1]);
//        cout<<i<<" "<<loc.first<<" "<<loc.second<<endl;
        if(loc>anss)
            anss = loc, pos = i;

        it = rest.find(nodes[i].x.second);
        if(it != rest.end())
        {
            rest.erase(it);
        }else
        {
            it = max_k.find(nodes[i].x.second);
            if(it != max_k.end() &&  rest.begin() != rest.end())
            {
                max_k.erase(it);
                it = rest.begin();
                max_k.insert(*it);
                sum += *it - nodes[i].x.second;
                rest.erase(it);
            }
        }
    }
    vector<int> ans;
//    cout<<anss.first<<" "<<anss.second<<endl;
    for(int i=pos-(p-k)-1;i<pos;i++)
    {
        ans.push_back(nodes[i].idx);
    }
    multiset<pair<int, int>, set_compare2> last;
    multiset<pair<int, int>, set_compare2>::iterator itt;
    for(int i=pos;i<n;i++)
        last.insert(make_pair(nodes[i].x.second, nodes[i].idx));
    int xx = 0;
    for(itt = last.begin(); xx<k-1; xx++, itt++)
        ans.push_back(itt->second);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    newline;
}
