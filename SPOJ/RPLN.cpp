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
int aux[100002][22];
int LOG2[100002];
int RMQ(int x, int y)
{
    int k = LOG2[y-x+1];
    return min(aux[x][k], aux[y-(1<<k)+1][k]);
}
int main()
{
    int z = 0;
    int curr = 2;
    LOG2[1] = 0;
    for(int i = 2; i<=100001;i++)
    {
        if(i == curr)
        {
            curr <<= 1;
            LOG2[i] = LOG2[i-1] + 1;
        }else
            LOG2[i] = LOG2[i-1];
    }
    in_T
    {
        z++;
        printf("Scenario #%d:\n", z);
        in_I(n);
        int q, x, y;
        in_I(q);
        for(int i=1;i<=n;i++)
            in_I(aux[i][0]);
        for(int j=1; (1<<j)<=n+1; j++)
            for(int i=1;i+(1<<j)<=n+1;i++)
                aux[i][j] = min(aux[i][j-1], aux[i+(1<<(j-1))][j-1]);
        while(q--)
        {
            in_I(x);
            in_I(y);
            printf("%d\n", RMQ(x, y));
        }
    }
}
