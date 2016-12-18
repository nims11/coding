/*
 * Solve it recursively using the matrix representation of Fibonacci numbers
 */
#include<cstdio>
#include<cmath>
using namespace std;
long long a1=0,a2=0;long long m =123456789;

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
    }
    if (n %2 ==1)
    {
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=(a+b)%m;
        M[0][1]=a%m;
        M[1][0]=(c+d)%m;
        M[1][1]=c%m;
    }
}
void fib(long long n)
{
    long long M[2][2] = {{1%m,0%m},{0%m,1%m}};
    matpow(n-1,M);
    a1=M[1][0];
    a2=M[0][0];
}
long long n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)a2=0;
        else
        fib(n-1);

        printf("%lld\n",((4*n)%m +a2 -1)%m);
    }
}
