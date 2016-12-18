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
#include<cassert>
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
const int m = 1000000007;
long long S[3][3];
long long B[3][3] = {{2, 2, 1}, {1, 0, 0}, {0, 1, 0}};
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
            }
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
            }
        }
    }
}
int getans(int n){
    if(n == 0)return 0;
    if(n == 1)return 2;
    if(n == 2)return 5;
    long long M[3][3] = {{2, 2, 1}, {1, 0, 0}, {0, 1, 0}};
    matpow(M,n-2);
    return (M[0][0]*5+M[0][1]*2)%m;
}
int main()
{
    in_T{
        int n;
        in_I(n);
        printf("%d\n", getans(n));
    }
}
