/*
    Nimesh Ghelani (nims11)
*/
#include<cstdio>
#include<cmath>

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
    while(in_I(n))
    {
        if(n==0)break;
        printf("%d\n",(int)(log(n)/log(2)));
    }
}
