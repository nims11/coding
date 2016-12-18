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
int mapp[100001];
int BIT[100001];
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
    in_T
    {
        in_I(n);
        int x;
        for(int i = 1; i<=n; i++)
        {
            in_I(x);
//            if(x > 100000)
//            {
//                return 0;
//            }
            mapp[x] = i;
        }
        for(int i = 1; i<=n; i++)
            BIT[i] = 0;
        long long ans = 0;
        for(int i = 0; i<n; i++)
        {
            in_I(x);
//            if(x > 100000)
//            {
//                return 0;
//            }
//            cout<<mapp[x]<<endl;
            update(mapp[x], n, 1);
            ans += query(n) - query(mapp[x]);
        }
        printf("%d\n", ans);
    }
}
