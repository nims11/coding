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
long long n, mod=1000000007;
long long tmp1,tmp2;
long long A,B,E,F,I,J,K,L,m,N,O,P;
void matpow(int M[4][4],long long n)
{
    if(n>1)
    {
        matpow(M,n/2);
        A = M[0][0],B=M[0][1],E=M[1][0],F=M[1][1],I=M[2][0],J=M[2][1],K=M[2][2],L=M[2][3],m=M[3][0],N=M[3][1],O=M[3][2],P=M[3][3];
        tmp1=(B*E)%mod;
        tmp2=(L*O)%mod;
        M[0][0] = ((A*A) + tmp1)%mod;
        M[0][1] = ((A*B) + (B*F))%mod;

        M[1][0] = ((E*A) + (F*E))%mod;
        M[1][1] = ((B*E) + (F*F))%mod;

        M[2][0] = ((I*A) + (J*E) + (K*I) + (L*m))%mod;
        M[2][1] = ((I*B) + (J*F) + (K*J) + (L*N))%mod;
        M[2][2] = ((K*K) + tmp2)%mod;
        M[2][3] = ((K*L) + (L*P))%mod;

        M[3][0] = ((m*A) + (N*E) + (O*I) + (P*m))%mod;
        M[3][1] = ((m*B) + (N*F) + (O*J) + (P*N))%mod;
        M[3][2] = ((O*K) + (P*O))%mod;
        M[3][3] = (tmp2 + (P*P))%mod;

        if(n&1)
        {
            A = M[0][0],B=M[0][1],E=M[1][0],F=M[1][1],I=M[2][0],J=M[2][1],K=M[2][2],L=M[2][3],m=M[3][0],N=M[3][1],O=M[3][2],P=M[3][3];

            tmp1=I+K;
            tmp2=m+O;

            M[0][0] = (A + B)%mod;
            M[0][1] = A;

            M[1][0] = (E + F)%mod;
            M[1][1] = E;

            M[2][0] = (tmp1 + J)%mod;
            M[2][1] = (tmp1)%mod;
            M[2][2] = (K+L)%mod;
            M[2][3] = K;

            M[3][0] = (tmp2 + N)%mod;
            M[3][1] = (tmp2)%mod;
            M[3][2] = (O + P)%mod;
            M[3][3] = O;
        }
    }
}
int fib()
{
    if(n==1)return 0;
    else if(n==2)return 5;

    int M[4][4] = {{1,1,0,0},{1,0,0,0},{1,1,1,1},{0,0,1,0}};
    matpow(M,n-2);
    return ((8LL*M[2][0])%mod + (5LL*(M[2][1] + M[2][2]))%mod)%mod;
}
int main()
{
    in_T
    {
        in_L(n);
        printf("%d\n",fib());
    }
}
