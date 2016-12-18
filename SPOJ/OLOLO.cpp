/*
 * keep XORing and you will get the answer
 * two XORs with same number negates it, so the number which was XORed once will remain at the end.
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
    int a;
    int t;
    in_I(t);
    t--;
    in_I(a);
    while(t--)
    {
        in_I(n);
        a=a^n;
    }
    printf("%d\n",a);
}
