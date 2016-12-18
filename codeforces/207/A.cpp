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
int nxt[300002];
int arr[300002];
int getnxt(int x)
{
    if(nxt[x] == x)
        return x;
    return (nxt[x] = getnxt(nxt[x]));
}
int main()
{
    int n,m;
    int l, r, x;
    in_I(n);
    in_I(m);
    for(int i = 1;i<=n+1;i++)
        nxt[i] = i;

    for(int i = 0;i<m;i++)
    {
        in_I(l);in_I(r);in_I(x);
        l = getnxt(l);
        while(l<=r)
        {
            if(l == x)
                l++;
            else
                arr[l] = x, nxt[l] = l+1;
            l = getnxt(l);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
        printf("%d ", arr[i]);
    newline;
}
