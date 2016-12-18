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
int arr1[2003],arr2[2003],dp[2003][2003],tmp,count_1,count_2;
int LCS_len()
{
    for(int i=0;i<=count_1;i++)
    dp[i][0]=0;
    for(int i=0;i<=count_2;i++)
    dp[0][i]=0;
    for(int i=0;i<count_1;i++)
    for(int j=0;j<count_2;j++)
    {
        if(arr1[i]==arr2[j])
            dp[i+1][j+1]=dp[i][j]+1;
        else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
    }
    return dp[count_1][count_2];
}
int main()
{
    in_T
    {
        int ans=0;
        count_1=0;
        while(1)
        {
            in_I(tmp);
            if(tmp==0)break;
            arr1[count_1++]=tmp;
        }
        while(1)
        {
            count_2=0;
            in_I(tmp);
            if(tmp==0)break;
            arr2[count_2++]=tmp;
            while(1)
            {
                in_I(tmp);
                if(tmp==0)break;
                arr2[count_2++]=tmp;
            }
            ans=max(ans,LCS_len());
        }
        printf("%d\n",ans);
    }
}
