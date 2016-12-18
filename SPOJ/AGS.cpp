/*
Objective: To find the nth term if the sequence which goes like a,a+d,(a+d)r,(a+d)r+d,((a+d)r+d)r,....

Solution: After analysing the sequence, an general form of the nth term can be derived. The main problem lies in optimizing the algo
to avoid TLE.
The main sites for optimization are the functions which compute the r^n and summation of r^n
the first one can be solved by dividing the exponential problem.
eg. for r^4, instead of proceeding as ((r*r)*r)*r which takes three operations,
(r*r)*(r*r) will take two operations (r*r is only computed once)

for the summation part, divide the problem into sub-problems.
eg. for r^3+r^2+r+1
it can be solved recursively as
1+r(1+r(1+r))
*/
#include<cstdio>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_L(a) scanf("%lld",&a)
long long a,d,r,n,mod,r_n,ans,s_m;
long long pow(long long r2,long long n)
{
    long long ans=1;
    while(n>0)
    {
        if((n&1)>0)
        ans=(ans*r2)%mod;
        n>>=1;
        r2=(r2*r2)%mod;
    }
    return ans%mod;
}
long long getSum(long long r,long long n)
{
    if(n==1)return 1;
    if(n==3)return (1+r+(r*r)%mod)%mod;
    else if(n==2)return (1+r)%mod;
    long long ans= (((1+r)*getSum((r*r)%mod,n/2))%mod)%mod;
    ans+=n%2?pow(r,n-1):0;
    return ans%mod;
}
int main()
{
    in_T
    {
        in_L(a);in_L(d);in_L(r);
        in_L(n);in_L(mod);
        r_n=pow(r,(n-1)/2);

        s_m=getSum(r,(n-1)/2);

        ans=((a%mod)*r_n)%mod;
        ans+=(s_m*((d%mod)*(r%mod)))%mod;
        if(n%2==0)ans+=d;
        printf("%lld\n",ans%mod);
    }
}

