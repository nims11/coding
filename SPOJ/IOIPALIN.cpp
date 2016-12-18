/*
AIBOHP with state optimization
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
int dp1[5002]={0}, dp2[5002]={0};
char str1[5002],str2[5002];
int len;
int LCS_len()
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(i%2==0){
                if(str1[i]==str2[j])
                    dp2[j+1]=dp1[j]+1;
                else dp2[j+1]=max(dp2[j],dp1[j+1]);
            }else
            {
                if(str1[i]==str2[j])
                    dp1[j+1]=dp2[j]+1;
                else dp1[j+1]=max(dp1[j],dp2[j+1]);
            }
        }
    }
    return len%2?dp2[len]:dp1[len];
}
int main()
{
    in_I(len);
        in_S(str1);

        for(int i=len-1;i>=0;i--)
        str2[len-1-i]=str1[i];
        str2[len]=0;

        int len2=LCS_len();
        printf("%d\n",len-len2);
}

