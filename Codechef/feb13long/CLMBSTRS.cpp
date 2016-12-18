/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int n,g;
int m = 1000000007;
void matpow(long long n,long long M[2][2])
{
    if (n > 1)
    {
        matpow(n/2,M);
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=((a*a)%m+(b*c)%m)%m;
        M[0][1]=((a*b)%m+(b*d)%m)%m;
        M[1][0]=((c*a)%m+(d*c)%m)%m;
        M[1][1]=((c*b)%m+(d*d)%m)%m;

        if (n %2 ==1)
        {
            long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
            M[0][0]=(a+b)%m;
            M[0][1]=a%m;
            M[1][0]=(c+d)%m;
            M[1][1]=c%m;
        }
    }
}
int fib(long long n)
{
    long long M[2][2] = {{1,1},{1,0}};
    matpow(n+1,M);
    return M[1][0];
}
int main()
{
    in_T
    {
        in_I(n);
        in_I(g);
        int foo = fib(n);
        int bar = 0;

        while(foo)
        {
            bar += foo&1;
            foo>>=1;
        }

        if(bar == g)
            printf("CORRECT\n");
        else
            printf("INCORRECT\n");
    }
}
