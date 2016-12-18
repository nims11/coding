/*
 * searching
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

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
    int n,a[2000],k,m,j,ans;
    while(1){
        in_I(n);
        if(n==0)break;
        ans=0;
        for(int i=0;i<n;i++)
        in_I(a[i]);
        std::sort(a,a+n);
        for(int i=0;i<n-2;i++)
        {
            for(j=i+1,m=i+2;j<n-1;j++)
            {
                k=a[i]+a[j];
                for(;m<n && a[m]<=k;m++);
                if(m==n)break;
                ans+=n-m;
            }
        }
        printf("%d\n",ans);
    }
}
