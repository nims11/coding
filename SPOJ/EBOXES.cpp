/*
    Nimesh Ghelani (nims11)
    A tricky question with a simple solution
    Using some basic math, write the formula for the empty boxes in end, group the unknowns as their sums and derive the formula for total boxes.
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
    in_T
    {
        int n,k,t,f;
        in_I(n);in_I(k);in_I(t);in_I(f);
        printf("%d\n",f+(f-n)/(k-1));
    }
}
