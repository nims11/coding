#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BAR 50000000
using namespace std;
int mod=1000000007;
int dp[BAR]={0};
int foo(int n)
{
    if(n<BAR && dp[n])return dp[n];
    int k=n>>1;
    int tmp=foo(k);
    int tmp2;
    if(n&1)tmp2=foo(n-k);
    else tmp2=tmp;


        tmp=((long long)tmp*tmp2)%mod;

        tmp2=((long long)2*foo(k-1)*foo(n-k-1))%mod;

    if(n<BAR)
    {
        dp[n]=( tmp + tmp2 )%mod;
        return dp[n];
    }
    return ( tmp + tmp2 )%mod;
}
int main()
{
    dp[0]=1;dp[1]=2;dp[2]=6;
//    while(1)
//    {
//        int n;
//        cin>>n;
//        cout<<foo(n)<<endl;
//    }

    int n;
    in_T
    {
        in_I(n);
//n=t+100000;
//cout<<n<<endl;
        if(n==1){printf("1\n");continue;}
//        (foo(n-1)+foo(n-2))%mod;
        printf("%d\n",(foo(n-1)+foo(n-2))%mod);
    }
}
