/*
 * Solve it recursively using the matrix representation of Fibonacci numbers
 */
#include<iostream>
#include<cmath>
using namespace std;
long a1=0,a2=0;

void matpow(long n,long M[2][2],long m)
{
    if (n > 1)
    {
        matpow(n/2,M,m);
        long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=((a*a)%m+(b*c)%m)%m;
        M[0][1]=((a*b)%m+(b*d)%m)%m;
        M[1][0]=((c*a)%m+(d*c)%m)%m;
        M[1][1]=((c*b)%m+(d*d)%m)%m;
    }
    if (n %2 ==1)
    {
        long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=(a+b)%m;
        M[0][1]=a%m;
        M[1][0]=(c+d)%m;
        M[1][1]=c%m;
    }
}
void fib(long n,long m)
{
    long M[2][2] = {{1%m,0%m},{0%m,1%m}};
    matpow(n-1,M,m);
    a1=M[1][0];
    a2=M[0][0];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long a,b,m,n;
        cin>>a>>b>>n>>m;
        fib(n+1,m);
        if(a2==0)
        a2=m;
        cout<<((((a%m)*(a1%m))%m)+((b%m)*((a2-1)%m))%m)%m<<endl;
    }
}
