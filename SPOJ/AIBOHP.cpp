/*
Objective: Find the minimum number of insertions required to convert a string to a palindrome.
Solution: simply find the LCS of the string and its reverse.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
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
int dp[6200][6200];
char str1[6200],str2[6200];
int len;
//int LCS_len(int a1,int a2)
//{
//    if(a1==-1 || a2==-1)
//    return 0;
//
//    if(dp[a1][a2]!=-1)return dp[a1][a2];
//
//    if(str1[a1]==str2[a2])dp[a1][a2]=LCS_len(a1-1,a2-1)+1;
//    else{
//    int foo=LCS_len(a1,a2-1),bar=LCS_len(a1-1,a2);
//    dp[a1][a2]=MAX(foo,bar);}
//    return dp[a1][a2];
//}
int LCS_len()
{
    for(int i=0;i<=len;i++)
    dp[i][0]=0;
    for(int i=0;i<=len;i++)
    dp[0][i]=0;
    for(int i=0;i<len;i++)
    for(int j=0;j<len;j++)
    {
        if(str1[i]==str2[j])
            dp[i+1][j+1]=dp[i][j]+1;
        else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
    }
    return dp[len][len];
}
int main()
{
    in_T
    {
        in_S(str1);
        len=strlen(str1);

        for(int i=len-1;i>=0;i--)
        str2[len-1-i]=str1[i];
        str2[len]=0;

        int len2=LCS_len();
        printf("%d\n",len-len2);
    }
}

