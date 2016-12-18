/*
    Nimesh Ghelani (nims11)
    Refer wikipedia
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
int mod = 1000000007;
int POW(long long r, int n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int main()
{
    in_T
    {
        int a,p;
        in_I(a);
        in_I(p);
        mod = p;
        if(p!=2)
        {
            int res = POW(a,(p-1)/2);
            if(res == p-1)
                res = -1;
            printf("%d\n", res);
        }else
        {
            a%=2;
            if(a == 0)
            {
                printf("%d\n", 0);
            }else
                printf("1\n");
        }
    }
}
