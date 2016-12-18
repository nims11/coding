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
int BIT[1000001];
int query(int idx)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
void update(int idx, int n, int val)
{
    while(idx<=n)
    {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}
int main()
{
    int n;
    in_I(n);
    int x;
    int inv = 0;
    for(int i = 0; i<n; i++)
    {
        in_I(x);
        inv += query(n) - query(x);
        update(x, n, 1);
    }
    if(inv == 0)
        cout<<0<<endl;
    else if(inv%2 == 1)
    {
        cout<<1+(inv-1)*2<<endl;
    }else
        cout<<inv*2<<endl;
}
