/*
 * sum of first n fibonacci numbers is F(n+2)
 * Solve it recursively using the matrix representation of Fibonacci numbers
 */
#include<iostream>
#include<cmath>
using namespace std;
long a1=0,a2=0;

void matpow(long long n,long long M[2][2],long long m)
{
    if (n > 1)
    {
        matpow(n/2,M,m);
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
void fib(long long n,long long m)
{
    long long M[2][2] = {{1%m,0%m},{0%m,1%m}};
    matpow(n-1,M,m);
    a1=M[1][0];
    a2=M[0][0];
}

int main()
{
    int t;
    cin>>t;
    int m=1000000007;
    while(t--)
    {
        int M,N;
        cin>>M>>N;
        long long ans;
        fib(N+3,m);
        ans=a1;
        fib(M+2,m);
        ans-=a1;
        if(ans<0)
        ans=m+ans;
        cout<<ans<<endl;
    }
}
