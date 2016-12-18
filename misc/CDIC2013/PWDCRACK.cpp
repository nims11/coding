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
int dp[1003][1003];
int main()
{
    char str1[1003],str2[1003];
    int len1,len2;
    int a,b,c;
    in_T
    {
        in_S(str1);in_S(str2);
        len1=strlen(str1);
        len2=strlen(str2);
        for(int i=0;i<=len2;i++)
        dp[0][i]=0;
        for(int i=0;i<=len1;i++)
        dp[i][0]=0;
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                a=dp[i-1][j-1]+ (str1[i-1]==str2[j-1]?0:1);
                b=1+dp[i][j-1];
                c=1+dp[i-1][j];
                dp[i][j]=min(a,min(b,c));
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
}
