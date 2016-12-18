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

int c[1000];
int n,k,tmp;
long long eval(int v)
{
    if(v==n)return c[v]*tmp;

    return tmp*(c[v]+eval(v+1));
}
int main()
{
    int cases=0;
    while(1)
    {
        cases++;
        in_I(n);
        if(n==-1)break;
        printf("Case %d:\n",cases);
        for(int i=n;i>=0;i--)
        in_I(c[i]);
        in_I(k);
        for(int i=0;i<k;i++)
        {
            in_I(tmp);
            printf("%lld\n",c[0]+eval(1));
        }
    }
}
