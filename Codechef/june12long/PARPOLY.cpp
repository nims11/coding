/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
long long m,n,x,mod=1000000007,d,c[100],tmp;
long long dp[1000];
long long curr[405],curr_count;
long long ans=0;
long long eval(int v)
{
    if(v==d)return (c[v]*tmp)%mod;
    return (tmp*((c[v]+eval(v+1))%mod))%mod;
}
long long permu()
{
    int tmpp[405];
    for(int i=0;i<curr_count;i++)tmpp[i]=i+1;
    int foo=1;
    for(int i=1;i<curr_count;i++)
    {
        if(curr[i]==curr[i-1])
        {
            foo++;
            for(int j=0;j<curr_count;j++)
            {
                if(tmpp[j]%foo==0)
                {
                    tmpp[j]/=foo;
                    break;
                }
            }
        }else
        foo=1;
    }
    long long ans=1;
    for(int i=0;i<curr_count;i++)
    {
        ans*=tmpp[i];
        ans%=mod;
    }
    return ans;
}
long long getans(int sum,int cnt,int start)
{
    printf("%d %d %d\n",sum,cnt,start);
    if(cnt==1)
    {
        if(sum>=start)
        {
            curr[curr_count++]=sum;
            long long ans=(dp[sum]*permu())%mod;
            curr_count--;
            return ans;
        }
        return 0;
    }

    int ans=0;
    for(int i=start;i<=sum;i++)
    {
        curr[curr_count++]=i;
        ans+=(dp[i]*getans(sum-i,cnt-1,i))%mod;
        curr_count--;
        ans%=mod;
    }
    return ans;
}
int main()
{
    in_T
    {
        ans=0;
        in_L(m);in_L(n);in_L(x);in_L(d);
        for(int i=0;i<=d;i++)
        in_L(c[i]);
        if(d>0)
        for(int i=0;i<=n;i++)
        {
            tmp=(x*i)%mod;
            dp[i]=c[0]+eval(1);
        }
        else
        for(int i=0;i<=n;i++)
        {
            tmp=(x*i)%mod;
            dp[i]=c[0];
        }

        curr_count=0;


        printf("%lld\n",getans(n,m,0));
    }
}
