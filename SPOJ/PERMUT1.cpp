/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
const int N=13,K=99;
int main()
{
    int ans[K][N]={0};
    for(int i=1;i<N;i++)
    ans[0][i]=1;
    for(int i=1;i<K;i++)
    {
        for(int j=1;j<N;j++)
        {
            for(int m=i;m>=0 && m>i-j;m--)
            ans[i][j]+=ans[m][j-1];
        }
    }
    in_T
    {
        int n,k;
        in_I(n);in_I(k);
        printf("%d\n",ans[k][n]);
    }
}
