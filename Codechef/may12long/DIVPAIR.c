#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,m;
        scanf("%ld%ld",&n,&m);
        long long count=0,oddcount,evencount;
        long long a=(2*n-1)/m;
        if(m%2==0)
        {
            count=((m/2)*a*(a+1))/2-a;
        }else
        {
            oddcount=(m*(((a+1)/2)*(2+((a+1)/2 -1)*2))/2-(a+1)/2)/2;
            //evencount=((m*(a/2)*(4+(a/2-1)*2))/2)/2-a/2;
            evencount=(m*(a/2)*(a/2+1))/2-a/2;
            count=oddcount+evencount;
        }
        a=(2*n-1)/m-(n+1)/m;
        if(a!=0)
        count-=m*(a*((n+1)/m) + (a*(a+1))/2)-a*(n+1);
        printf("%ld\n",count);
    }
    return 0;
}
