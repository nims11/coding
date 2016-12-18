/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int n,k,foo,bar;
int main()
{
    in_T
    {
        in_I(n);in_I(k);
        bar = 1;
        for(int i=0;i<n/2-1;i++)
        bar*=10;
        if(n%2==0)
        {
            foo = bar+k-1;
            printf("%d",foo);
            while(foo)
            {
                printf("%d",foo%10);
                foo/=10;
            }
        }else
        {
            bar = bar+((k-1)/10);
            printf("%d%d",bar,(10+k-1)%10);
            while(bar)
            {
                printf("%d",bar%10);
                bar/=10;
            }
        }
        newline;
    }
}
