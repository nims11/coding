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
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int mod = 1000000007;
int B[2][2] = {{2,3},{1,1}};
void matpow(long long M[2][2], int n)
{
    if(n>1)
    {
        matpow(M,n/2);
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0] = ((a*a)%mod + (b*c)%mod)%mod;
        M[0][1] = ((a*b)%mod + (b*d)%mod)%mod;
        M[1][0] = ((c*a)%mod + (d*c)%mod)%mod;
        M[1][1] = ((c*b)%mod + (d*d)%mod)%mod;
        if(n&1)
        {
            long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
            M[0][0] = ((a*2)%mod + b)%mod;
            M[0][1] = ((a*3)%mod);
            M[1][0] = ((c*2)%mod + d)%mod;
            M[1][1] = ((c*3)%mod);
        }
    }
}
int ans(int n)
{
    if(n==2)return 12;
    if(n==3)return 24;
    long long M[2][2] = {{2,3},{1,0}};
    matpow(M,n-3);
    return ((M[0][0]*24)%mod + (M[0][1]*12)%mod)%mod;
}
int main()
{
    int n;
    in_T
    {
        in_I(n);
        printf("%d\n",ans(n));
    }
}
