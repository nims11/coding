/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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
static int len, dp[2][100003],ans, i,tmp;
static char s1[100003];
using namespace std;
int main()
{
    in_I(len);
    in_S(s1);
    for(;i<len;i++)
    {
        tmp = (i%2);
        for(int j=1; j<=len;j++)
        {
            if(s1[i]==s1[len-j])
            {
                dp[tmp][j]=dp[!tmp][j-1]+1;
                if(ans<dp[tmp][j])
                ans = dp[tmp][j];
            }
            else
                dp[tmp][j]=0;
        }
    }
    printf("%d\n",ans);
}

