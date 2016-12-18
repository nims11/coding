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
#include<set>
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
int m;
void matpow(int n,int M[2][2])
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
int fib(int n)
{
    if(n==0)return 0;
    int M[2][2] = {{1, 1}, {1, 0}};
    matpow(n, M);
    return M[1][0];
}
int main()
{
    in_T
    {
        int n;
        in_I(n);
        in_I(m);
        printf("%d\n", ((fib(n+4)-3)%m+m)%m);
    }
}
