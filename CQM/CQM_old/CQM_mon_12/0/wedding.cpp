/*
    Nimesh Ghelani (nims11)
    DP
    similar to LCS. Objective is to transform str1 to str2 by insertion,deletion or transformation.
    Code is self explanatory.
*/
#include<iostream>
#include<cstdio>
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
int dp[2003][2003];
int main()
{
    char str1[2003],str2[2003];
    int len1,len2;
    int a,b,c,n;
    in_T
    {
        in_I(n);
        cin.ignore(1);
        cin.getline(str1,250);cin.getline(str2,250);
        len1=strlen(str1);
        len2=strlen(str2);
        for(int i=0;i<=len2;i++)
        dp[0][i]=i;
        for(int i=0;i<=len1;i++)
        dp[i][0]=i;
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
        printf("Rs. %d\n",2*n*dp[len1][len2]);
    }
}
