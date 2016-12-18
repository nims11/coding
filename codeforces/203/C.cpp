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
int n;
pair<int, int> pts[100001];
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(abs(a.first) == abs(b.first))
        return abs(a.second)<abs(b.second);
    return abs(a.first)<abs(b.first);
}
struct node{
    int type, n1, n2;
}tmp;
int main()
{
    in_I(n);
    for(int i = 0; i<n; i++)
    {
        in_I(pts[i].first);
        in_I(pts[i].second);
    }
    sort(pts, pts+n, cmp);
    vector<node> ans;
    for(int i = 0; i<n; i++)
    {
            tmp.type = 1;
        if(pts[i].first != 0)
        {
            tmp.n1 = abs(pts[i].first);
            tmp.n2 = pts[i].first>0?1:3;
            ans.push_back(tmp);
        }
        if(pts[i].second != 0)
        {
            tmp.n1 = abs(pts[i].second);
            tmp.n2 = pts[i].second>0?0:2;
            ans.push_back(tmp);
        }
        tmp.type = 2;
        ans.push_back(tmp);
        tmp.type = 1;
        if(pts[i].first != 0)
        {
            tmp.n1 = abs(pts[i].first);
            tmp.n2 = pts[i].first>0?3:1;
            ans.push_back(tmp);
        }
        if(pts[i].second != 0)
        {
            tmp.n1 = abs(pts[i].second);
            tmp.n2 = pts[i].second>0?2:0;
            ans.push_back(tmp);
        }
        tmp.type = 3;
        ans.push_back(tmp);
    }
    cout<<ans.size()<<endl;
    char str[] = "URDL";
    for(int i = 0; i<ans.size(); i++)
    {
        if(ans[i].type == 1)
        {
            printf("%d %d %c\n", ans[i].type, ans[i].n1, str[ans[i].n2]);
        }else
            printf("%d\n", ans[i].type);
    }
}
