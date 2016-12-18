/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
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
int ans[5000004];
int main()
{
    ans[1]=1;
    long long sum=1;
    long long mod = 1000000007;
    for(int i=2;i<=5000003;i++)
    {
        ans[i] = (2*sum)%mod;
        sum = (sum+ans[i])%mod;
    }
    int n;
    in_T
    {
        in_I(n);
        printf("%d\n",ans[n]);
    }
}
