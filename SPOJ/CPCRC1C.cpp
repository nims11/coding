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
int len_n(int n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n/=10;
    }
    return ans;
}
int bar [11] = {0,0,1,3,6,10,15,21,28,36,45};
long long dp[10];
int get_sum(int n)
{
    if(n<=0)return 0;
    int res = 0;
    while(n)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
long long f(long long n)
{
    long long len = len_n(n);
    long long foo=1;
    long long curr_dig;
    long long ans=0;
    for(int i=0;i<len&&n>0;i++,foo*=10)
    {
        curr_dig=n%(foo*10);
        long long first_dig = (n/foo)%10;
        n-=curr_dig;
        ans+=dp[i]*first_dig+bar[first_dig]*foo + first_dig + get_sum(n)*curr_dig;
//        cout<<curr_dig<<" "<<n<<"* "<<ans<<endl;
    }
//    cout<<ans<<endl;
    return ans;
}
int main()
{
    dp[0]=0;
    dp[1]=45;
    long long foo = 1;
    for(int i=2;i<10;i++)
    {
        foo*=10;
        dp[i] = 10*dp[i-1] + foo*45;
    }
    int a,b;
//    f(274);
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==-1)
        return 0;
        printf("%lld\n",f(b)-f(a-1));
    }
}
