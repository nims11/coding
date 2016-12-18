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
long long mod = 1000000007;
long long POW(long long r, long long n)
{
    long long ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
long long V,N,A0,B0,C0,M0,A1,B1,C1,M1;
long long P[102], Q[102];
long long L[102];
int main()
{
    in_T
    {
        scanf("%lld%lld", &V, &N);
        scanf("%lld%lld%lld%lld%lld%lld", &P[0], &P[1], &A0, &B0, &C0, &M0);
        scanf("%lld%lld%lld%lld%lld%lld", &Q[0], &Q[1], &A1, &B1, &C1, &M1);
        A0 = (A0*A0)%M0;
        A1 = (A1*A1)%M1;

        for(int i=2;i<N;i++)
        {
            P[i] = (((A0*P[i-1])%M0 + (B0*P[i-2])%M0)%M0 + C0)%M0;
            Q[i] = (((A1*Q[i-1])%M1 + (B1*Q[i-2])%M1)%M1 + C1)%M1;
        }

        for(int i=0;i<N;i++)
            L[i] = P[i]*M1 + Q[i] + 1;

        long long foo = 1;
        int x = 0;
        for(int i=0;i<N;i++)
        {
            x += (L[i]==1);
            foo = (((L[i]-1)%(mod-1))*foo)%(mod-1);
        }
        if(V%mod == 0 && x != 0)
            printf("1\n");
        else if(V%mod == 0)
            printf("0\n");
        else printf("%lld\n", POW(V%mod, foo));
    }
}
