#include<cmath>
#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        double s=(a+b+c+d)/2;
        double ans=sqrt((s-a)*(s-b)*(s-c)*(s-d));
        printf("%.2lf\n",ans);
    }
}
