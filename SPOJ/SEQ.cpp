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
#define in_L(a) scanf("%ull",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
long long unsigned M[10][10], B[10][10], C[10];
int k, mod = 1000000000;
long long unsigned T[10][10];
void mat_pow(long long unsigned M[10][10], int n)
{
    if(n>1)
    {
        mat_pow(M,n/2);
        for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            T[i][j] = M[i][j];
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                M[i][j]=0;
                for(int a=0;a<k;a++)
                    M[i][j]= (M[i][j] + ((T[i][a]*T[a][j])%mod))%mod;
            }
        }
        if(n&1)
        {
            for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                T[i][j] = M[i][j];
            for(int i=0;i<k;i++)
            {
                for(int j=0;j<k;j++)
                {
                    M[i][j]=0;
                    for(int a=0;a<k;a++)
                        M[i][j]= (M[i][j] + ((T[i][a]*B[a][j])%mod))%mod;
                }
            }
        }
    }
}
int rec(int n)
{
    if(n<=k)
        return C[k-n]%mod;
    mat_pow(M,n-k);
    long long unsigned ans=0;
    for(int i =0;i<k;i++)
    {
        ans = (ans + ((C[i]*M[0][i])%mod))%mod;
    }
    return ans;
}
int main()
{
    in_T
    {
        in_I(k);
        for(int i=k-1;i>=0;i--)
            in_L(C[i]);
        for(int i=0;i<k;i++)
        {
            in_L(B[0][i]);
            M[0][i]=B[0][i];
        }
        for(int i=1;i<k;i++)
        {
            for(int j=0;j<k;j++)
            B[i][j] = M[i][j] =0;
            B[i][i-1] = M[i][i-1] =1;
        }
        int n;
        in_I(n);
        P_I(rec(n));
        newline;
    }
}
