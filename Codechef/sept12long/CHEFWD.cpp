/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
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
long long n,mod=1000000007;
void matpow(long long M[2][2],int n, long long x)
{
    if(n>1)
    {
        matpow(M,n/2,x);
        long long a = M[0][0], b = M[0][1], c = M[1][0], d = M[1][1];
        M[0][0] = ((a*a)%mod + (b*c)%mod)%mod;
        M[0][1] = ((a*b)%mod + (b*d)%mod)%mod;
        M[1][0] = ((a*c)%mod + (c*d)%mod)%mod;
        M[1][1] = ((b*c)%mod + (d*d)%mod)%mod;
    }
    if(n&1 && n>1)
    {
        long long a = M[0][0], b = M[0][1], c = M[1][0], d = M[1][1];
        M[0][0] = (x*(a+b))%mod;
        M[0][1] = (a*x)%mod;
        M[1][0] = (x*(c+d))%mod;
        M[1][1] = (c*x)%mod;
    }
}
long long fib(int n, long long start)
{
    long long M[2][2] = {{1,1},{1,0}};
    matpow(M,n,1);
    return start*M[0][0];
}
int main()
{
    cout<<fib(2,2)<<endl;
    in_T
    {
        in_L(n);
        long long ans = 0;
        for(int i=1;i<n;i++)
        {
            ans = (ans + fib(n-i+1,fib(i,1)) + fib(n-i+2,fib(i,1)))%mod;
        }
        cout<<ans<<endl;
    }
}
