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
#include<cstring>
#include<cstdlib>
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
long long m,n;
long long S[3][3];
long long B[3][3] = {{6, -1, 1}, {1, 0, 0}, {0, 0, 1}};
void matpow(long long M[3][3], long long n)
{
    if(n>1)
    {
        matpow(M, n>>1);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                S[i][j] = M[i][j];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                M[i][j] = 0;
                for(int k=0;k<3;k++)
                    M[i][j] = (M[i][j] + (S[i][k]*S[k][j])%m)%m;
//                cout<<M[i][j]<<" ";
            }
//            cout<<endl;
        }
    }
    if(n>1 && n&1)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                S[i][j] = M[i][j];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                M[i][j] = 0;
                for(int k=0;k<3;k++)
                    M[i][j] = (M[i][j] + (S[i][k]*B[k][j])%m)%m;
//                cout<<M[i][j]<<" ";
            }
//            cout<<endl;
        }
    }
}
long long ans()
{
    if(n == 1)
        return 3;
    long long M[3][3] = {{6, -1, 1}, {1, 0, 0}, {0, 0, 1}};
    matpow(M, n-1);
    return (M[0][0]*3+2*M[0][2])%m;
}
void matpow2(long long M[2][2], long long n)
{
    if(n>1)
    {
        matpow2(M, n>>1);
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                S[i][j] = M[i][j];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                M[i][j] = 0;
                for(int k=0;k<2;k++)
                    M[i][j] = (M[i][j] + (S[i][k]*S[k][j])%m)%m;
//                cout<<M[i][j]<<" ";
            }
//            cout<<endl;
        }
    }
    if(n>1 && n&1)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                S[i][j] = M[i][j];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                M[i][j] = 0;
                for(int k=0;k<2;k++)
                    M[i][j] = (M[i][j] + (S[i][k]*B[k][j])%m)%m;
//                cout<<M[i][j]<<" ";
            }
//            cout<<endl;
        }
    }
}
long long ans2()
{
    if(n == 1)
        return 5;
    long long M[2][2] = {{6, -1}, {1, 0}};
    matpow2(M, n-1);
    return (M[0][0]*5+M[0][1])%m;
}
int main()
{
    in_T
    {
        in_L(n);
        in_L(m);
        printf("%lld %lld\n", (ans()+m)%m, (ans2()+m)%m);
    }
}
