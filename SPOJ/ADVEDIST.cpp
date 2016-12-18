/*
    Nimesh Ghelani (nims11)
    DP
    Similar to EDIST
    for swapping in dp[i][j], find source[i]'s occurance in target[1..j-1] and similarly for target--source
    Thus, the pairs to swap are found for source and dest. delete all the inbetween elt for source and insert for target (ie add +1 to answer) and use the dp value
    corresponding to before start point of the two pairs.
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
int dp[1003][1003];
int main()
{
    char str1[1003],str2[1003];
    int len1,len2;
    int a,b,c, d;
    while(1)
    {
        in_S(str1);in_S(str2);
        if(str1[0] == '*')
            return 0;
        len1=strlen(str1);
        len2=strlen(str2);
        for(int i=0;i<=len2;i++)
        dp[0][i]=i;
        for(int i=0;i<=len1;i++)
        dp[i][0]=i;
        int pre_i[len1][26], pre_j[len2][26];
        int prev[26];
        for(int i=0;i<26;i++)
            prev[i] = -1;
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<26;j++)
            pre_i[i][j] = prev[j];
            prev[str1[i]-'a'] = i;
        }
        for(int i=0;i<26;i++)
            prev[i] = -1;
        for(int i=0;i<len2;i++)
        {
            for(int j=0;j<26;j++)
            pre_j[i][j] = prev[j];
            prev[str2[i]-'a'] = i;
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                a=dp[i-1][j-1]+ (str1[i-1]==str2[j-1]?0:1);
                b=1+dp[i][j-1];
                c=1+dp[i-1][j];
                dp[i][j]=min(a,min(b,c));
                if(i>1 && j>1 && pre_i[i-1][str2[j-1]-'a']!=-1 && pre_j[j-1][str1[i-1]-'a']!=-1)
                {
                    dp[i][j] = min(dp[i][j], dp[pre_i[i-1][str2[j-1]-'a']][pre_j[j-1][str1[i-1]-'a']] + 1 + (i-pre_i[i-1][str2[j-1]-'a']-2) + (j-pre_j[j-1][str1[i-1]-'a']-2));
                }
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
}
