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
int bl_r[1001], bl_c[1001];
int main()
{
    int n, m;
    in_I(n);
    in_I(m);
    while(m--)
    {
        int x, y;
        in_I(x);
        in_I(y);
        bl_r[x] = 1;
        bl_c[y] = 1;
    }
    int ans = 0;
    for(int i=2;i<=(n+1)/2;i++)
    {
        int a[4];
        a[0] = !bl_r[i];
        a[1] = !bl_c[i];
        a[2] = !bl_r[n-i+1];
        a[3] = !bl_c[n-i+1];
        if(i == n-i+1)
        {
            if(a[0] || a[1])
                ans++, bl_r[i] = bl_c[i] = 1;
            continue;
        }
        int cc = (!bl_c[i] + !bl_c[n-i+1]);
        int rr = (!bl_r[i] + !bl_r[n-i+1]);
        if(cc == 2)
        {
            ans += cc+rr;
        }else if (cc == 1)
        {
            ans += cc+rr;
        }else if(cc == 0)
            ans += rr;
    }
    cout<<ans<<endl;

}
