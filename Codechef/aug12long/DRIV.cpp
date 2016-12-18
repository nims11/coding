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
int main()
{
    int m = 1000000007;
    int foo[20]={0,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1};
    in_T
    {
        char str[20003];
        in_S(str);
        long long dp[10][4] = {0};
        int k;
        for(int i=0;str[i];i++)
        {
            long long dp2[10][4];
            for(int j=0;j<10;j++)for(int a=0;a<4;a++)dp2[j][a]=dp[j][a];

            k = str[i]-'0';
            for(int j=0;j<10;j++)
            {
                for(int a=0;a<3;a++)
                dp[foo[j+k]][a+1]=(dp[foo[j+k]][a+1]+dp2[j][a])%m;
            }
            dp[k][0]++;
        }
        printf("%d\n",(dp[9][0]+dp[9][1]+dp[9][2]+dp[9][3])%m);
    }
}
