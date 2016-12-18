/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
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
int dp[1000020]={0};
int k,l,m,a;
int main()
{
    for(int i=1000001;i<1000020;i++)
    dp[i]=1;
    in_I(k);in_I(l);in_I(m);
    dp[0]=-1;
    for(int i=0;i<1000001;i++)
    {
        a=-dp[i];

        if(!dp[i+1] || a==1)
        dp[i+1]=a;

        if(!dp[i+l] || a==1)
        dp[i+l]=a;

        if(!dp[i+k] || a==1)
        dp[i+k]=a;
    }
//    cout<<"DONE\n";
    for(int i=0;i<m;i++)
    {
        in_I(a);
        printf("%c",dp[a]==1?'A':'B');
    }
    newline;
}
