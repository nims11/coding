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
    char ch[4]={'R','D','L','U'};
    in_T
    {
        long long r,c;
        in_L(r);
        in_L(c);
        if(r==c)
        printf("%c\n",ch[(c+r-2)%4]);
        else
        if(r<c)
        printf("%c\n",ch[(2*r-2)%4]);
        else
        printf("%c\n",ch[(2*c-1)%4]);
    }
    return 0;
}
