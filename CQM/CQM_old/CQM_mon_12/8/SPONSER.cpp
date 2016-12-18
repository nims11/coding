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
#include<stack>
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
bool dp[10000001];
int n,tmp;
int main()
{
    in_T
    {
        in_I(n);
        bool flag = false;
        int lt = 100*n;
        int sum=0;
        dp[0]=1;
        for(int i=1;i<=lt;i++)
            dp[i] = false;
        for(int i=0;i<n;i++)
        {
            in_I(tmp);
            for(int j=0;j<=sum && !flag;j++)
            {
                if(dp[j])
                {
                    if(dp[j+tmp])
                    {
                        flag=true;
                        break;
                    }else
                    dp[j+tmp] = true;
                }
            }
            sum+=tmp;
        }
        if(flag)printf("YES\n");
        else    printf("NO\n");
    }
}
