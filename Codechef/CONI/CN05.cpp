/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
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
#define BE(a) a.begin(), a.end()

using namespace std;
int mod =1000000007;
int m = mod;
void matpow(long long n,long long M[2][2])
{
    if (n > 1)
    {
        matpow(n/2,M);
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=((a*a)+(b*c))%m;
        M[0][1]=((a*b)+(b*d))%m;
        M[1][0]=((c*a)+(d*c))%m;
        M[1][1]=((c*b)+(d*d))%m;
    }
    if ( n>1 && n %2 ==1)
    {
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=(a*2+b*3)%m;
        M[0][1]=a%m;
        M[1][0]=(c*2+d*3)%m;
        M[1][1]=c%m;
    }
}
long long fib(int n)
{
    if(n == 1)
        return 5;
    if(n == 0)
        return 2;
    long long M[2][2] = {{2,1},{3,0}};
    matpow(n-1, M);
    return (5LL*M[0][0]+2LL*M[1][0])%mod;
}
int main()
{
    in_T{
        int n;
        in_I(n);
        printf("%lld\n", fib(n));
    }
}
