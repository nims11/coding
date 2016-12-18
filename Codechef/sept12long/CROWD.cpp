
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
long long m = 1000000007;
void matpow(long long unsigned n,long long unsigned M[3][3])
{
    if (n > 1)
    {
        matpow(n/2,M);
        long long unsigned a=M[0][0],b=M[0][1],c=M[0][2],d=M[1][0],e=M[1][1],f=M[1][2],g=M[2][0],h=M[2][1],i=M[2][2];
        M[0][0]=((a*a)%m+(b*d)%m+(c*g)%m)%m;
        M[0][1]=((a*b)%m+(b*e)%m+(c*h)%m)%m;
        M[0][2]=((a*c)%m+(b*f)%m+(c*i)%m)%m;

        M[1][0]=((d*a)%m+(e*d)%m+(f*g)%m)%m;
        M[1][1]=((d*b)%m+(e*e)%m+(f*h)%m)%m;
        M[1][2]=((d*c)%m+(e*f)%m+(f*i)%m)%m;

        M[2][0]=((g*a)%m+(h*d)%m+(i*g)%m)%m;
        M[2][1]=((g*b)%m+(h*e)%m+(i*h)%m)%m;
        M[2][2]=((g*c)%m+(h*f)%m+(i*i)%m)%m;

    }
    if (n>1 && n %2 ==1)
    {
        long long unsigned a=M[0][0],b=M[0][1],c=M[0][2],d=M[1][0],e=M[1][1],f=M[1][2],g=M[2][0],h=M[2][1],i=M[2][2];
        M[0][0]=((a*1)%m+(b*1)%m+(c*0)%m)%m;
        M[0][1]=((a*1)%m+(b*0)%m+(c*1)%m)%m;
        M[0][2]=((a*1)%m+(b*0)%m+(c*0)%m)%m;

        M[1][0]=((d*1)%m+(e*1)%m+(f*0)%m)%m;
        M[1][1]=((d*1)%m+(e*0)%m+(f*1)%m)%m;
        M[1][2]=((d*1)%m+(e*0)%m+(f*0)%m)%m;

        M[2][0]=((g*1)%m+(h*1)%m+(i*0)%m)%m;
        M[2][1]=((g*1)%m+(h*0)%m+(i*1)%m)%m;
        M[2][2]=((g*1)%m+(h*0)%m+(i*0)%m)%m;
    }
}
long long fib(long long n)
{
    long long unsigned M[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
    matpow(n+1,M);
    return M[0][0];
}
long long pow(long long unsigned r2,long long n)
{
    long long ans=1;
    while(n>0)
    {
        if((n&1)>0)
        ans=(ans*r2)%m;
        n>>=1;
        r2=(r2*r2)%m;
    }
    return ans%m;
}
int main()
{
    cout<<pow(2,1000000000000000);
	in_T
	{
		long long n;
		in_L(n);
		long long a = pow(2,n), b = fib(n);
		if(a<b) a = m + a;
		long long res = (a-b)%m;
		cout<<res<<endl;
	}
}
