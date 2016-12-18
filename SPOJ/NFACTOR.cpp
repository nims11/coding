/*
    Nimesh Ghelani (nims11)
    Modify the Erastosthenes Sieve Algo
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
int sieve[1000001];
int ans[1000001][11];
int a,b,n;
int main()
{
    for(int i=2;i<=1000000;i++)
    {
        if(!sieve[i])
        {
            for(int j=i;j<=1000000;j+=i)
                sieve[j]++;
        }
    }
    ans[0][0] = 1;
    for(int i=1;i<=1000000;i++)
    {
        for(int j=0;j<=10;j++)
            ans[i][j]=ans[i-1][j];
        if(sieve[i]<=10)
            ans[i][sieve[i]]++;
    }
    in_T
    {
        scanf("%d%d%d", &a, &b, &n);
        printf("%d\n", ans[b][n]-ans[a-1][n]);
    }
}

