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
void matpow(long long n,long long M[2][2])
{
//    cout<<M[0][0]<<" "<<M[0][1]<<" "<<M[1][0]<<" "<<M[1][1]<<endl;
    if (n > 1)
    {
        matpow(n/2,M);
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=((a*a)%m+(b*c)%m)%m;
        M[0][1]=((a*b)%m+(b*d)%m)%m;
        M[1][0]=((c*a)%m+(d*c)%m)%m;
        M[1][1]=((c*b)%m+(d*d)%m)%m;

    }
    if (n>1 && n %2 ==1)
    {
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=(2*a+b)%m;
        M[0][1]=a%m;
        M[1][0]=(2*c+d)%m;
        M[1][1]=c%m;
    }
}
int fib(long long n)
{
    long long M[2][2] = {{2,1},{1,0}};
    matpow(n,M);
//    cout<<M[0][0]<<" "<<M[0][1]<<" "<<M[1][0]<<" "<<M[1][1]<<endl;
    return M[0][1];
}
int main()
{
    in_T
    {
        long long n;
        in_L(n);
        cout<<fib(n)<<endl;
    }
}
