/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
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
#define PI
int main()
{
    in_T
    {
        long long n;
        in_L(n);
        if(n==1)
        printf("1\n");
        else
        printf("%lld\n",(long long int)floor((log(2*acos(-1)*n)/2+n*(log(n)-1))/log(10))+1);
    }
}
