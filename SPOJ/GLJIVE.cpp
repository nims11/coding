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

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int main()
{
    int ans=0;
    int n;
    for(int i=0;i<10;i++)
    {
        in_I(n);
        ans+=n;
        if(ans>100)
        {
            ans=ans-100>100-(ans-n)?ans-n:ans;
            break;
        }
    }
    printf("%d\n",ans);
}
