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
struct node
{
    int type, pre, next;
}a[100001];
int res[100001];
int sz[100001];
int viz[100001];
int xy = 1;
int dfs(int idx)
{
    if(viz[idx] == xy)
        return -100;
    viz[idx] = xy;

    if(res[idx] != -1)
        return res[idx];

    int &ret = res[idx];

    if(a[idx].type == 1)
        return (ret = 1);

    if(a[idx].next == 0 || sz[idx] != 1)
        return (ret=-100);
    ret = dfs(a[idx].next);
    if(ret != -100)
        return ++ret;
    else
        return ret;
}
int main()
{
    in_I(n);
    for(int i = 1;i<=n;i++)
    {
        in_I(a[i].type);
        a[i].pre = a[i].next = 0;
    }
    for(int i = 1;i<=n;i++)
    {
        in_I(a[i].pre);
        a[a[i].pre].next = i;
        sz[a[i].pre]++;
        res[i] = -1;
    }
    int ans = -1, ans_i;
    for(int i = 1; i<=n ;i++)
    {
        if(res[i] == -1)
        {
            dfs(i);
            if(ans < res[i])
                ans = res[i], ans_i = i;
            xy++;
        }
    }
    cout<<ans<<endl;
    while(a[ans_i].type == 0)
    {
//        cout<<ans_i<<" "<<a[ans_i].type<<endl;
        printf("%d ", ans_i);
        ans_i = a[ans_i].next;
    }
    printf("%d\n", ans_i);
}
