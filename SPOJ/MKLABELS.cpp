/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int main()
{
    int n;
    int ans[11];
    ans[1]=1;
    for(int i=2;i<=10;i++)
    {
        ans[i]=1;
        for(int j=0;j<i-2;j++)
        ans[i]*=i;
    }
    int a=0;
    while(in_I(n))
    {
        a++;
        if(n==0)break;
        printf("Case %d, N = %d, # of different labelings = %d\n",a,n,ans[n]);
    }
}
