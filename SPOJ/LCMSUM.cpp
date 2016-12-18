/*
    Nimesh Ghelani (nims11)
*/
#include<stdio.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)

long long ans2[1000001],p;
int ans[1000001];
int N = 1000000,j,n,i;
void aaa()
{
    for (i=1;i<=N;i++)
    ans[i] = i;
    for (i=2;i<=N;i++)
    if(ans[i]==i)
    for (n=i+i;n<=N;n+=i)
    ans[n]-=ans[n]/i;

    for(p=1;p<=N;p++)
    { if(p!=1 && ans[p]==p)ans[p]--;
        for(j=p;j<=N;j+=p)
    ans2[j]+=ans[p]*p;
    }
}
int main()
{
    aaa();
    in_T
    {
        in_I(n);
        printf("%lld\n",(1+ans2[n])*n/2);
    }
}
