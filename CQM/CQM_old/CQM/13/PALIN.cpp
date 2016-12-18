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
#include<cmath>
#include<stack>
#include<set>
#include<cstring>
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
int dp[200][200];
char str1[200],str2[200];
int len;
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
        while(in_S(str1) != EOF){
        len=strlen(str1);

        for(int i=len-1;i>=0;i--)
        str2[len-1-i]=str1[i];
        str2[len]=0;

        int len2=LCS_len();
        printf("%d\n",len-len2);
        }
}

