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
int main()
{
    long long fact[14];
    fact[0] = 1;
    for(int i=1;i<14;i++)
        fact[i] = fact[i-1]*i;
    int n,k;
    while(cin>>n>>k)
    {
        int tmp;
        long long ans = 1;
        int sum  = 0;
        for(int i=0;i<k;i++)
        {
            in_I(tmp);
            ans*=(fact[n-sum]/fact[tmp])/fact[n-sum-tmp];
            sum+=tmp;
        }
        printf("%lld\n",ans);
    }
}
