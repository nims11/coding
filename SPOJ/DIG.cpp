/*
    Nimesh Ghelani (nims11)
    C(n, 4)
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
int main()
{
    in_T
    {
        int foo[5];
        for(int i=2;i<=4;i++)
            foo[i] = 1;
        long long n;
        in_L(n);
        long long ans = 1;
        for(int i=0;i<=3;i++)
        {
            long long x = n-i;
            for(int j=4;j>=2;j--)
            {
                if(foo[j] && x%j == 0)
                {
                    x/=j;
                    foo[j] = 0;
                }
            }
            ans = (ans*x)%mod;
        }
        printf("%lld\n", ans);
    }
}
