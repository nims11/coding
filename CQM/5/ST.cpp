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
int N,D;
int d[10002];
char str[10002][5];
int getans(int x, int y)
{
    int curr1 = d[x], curr2 = d[x];
    int r1 = 0, r2 = 0;
    for(int i = x+1;i<y;i++)
    {
        if(i%2)
        {
            r2 = max(r2, d[i]-curr2);
            curr2 = d[i];
        }else
        {
            r1 = max(r1, d[i]-curr1);
            curr1 = d[i];
        }
    }
    r1 = max(r1, d[y]-curr1);
    r2 = max(r2, d[y]-curr2);
    return max(r1, r2);
}
int main()
{
    int z = 0;
    in_T
    {
        z++;
        in_I(N);in_I(D);
        for(int i = 1;i<=N;i++)
        {
            scanf("%s %d", str[i], &d[i]);
        }
        str[0][0] = str[N+1][0] = 'S';
        d[0] = 0;
        d[N+1] = D;
        int res = 0;
        int pre = 0;
        for(int i = 1;i<=N+1;i++)
        {
            if(str[i][0] == 'S')
            {
                res = max(res, getans(pre, i));
                pre = i;
            }
        }
        printf("Case %d: %d\n", z, res);
    }
}
