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
int dp[100][100];
int arr[100];
int n,k,tmp;
int getans(int pos,int balance)
{
    if(dp[pos][2*n-balance]!=-1)return dp[pos][2*n-balance];
    if(balance<0)return 0;
    if(balance==0 && pos==2*n)return 1;
    if(balance>0 && pos==2*n)return 0;

    if(arr[pos])
    {
        return getans(pos+1,balance+1);
    }
    int ans=0;
    ans+=getans(pos+1,balance+1);
    ans+=getans(pos+1,balance-1);
    dp[pos][2*n-balance]=ans;
    return ans;
}
int main()
{
    in_T
    {
        in_I(n);in_I(k);
        for(int i=0;i<=2*n;i++)
        {
            arr[i]=0;
            for(int j=0;j<=2*n;j++)
            dp[i][2*n-j]=dp[i][2*n+j]=-1;
        }
        for(int i=0;i<k;i++)
        {
            in_I(tmp);
            arr[tmp-1]=1;
        }
        int ans;
        printf("%d\n",getans(0,0));
    }
}
