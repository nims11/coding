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
    in_T
    {
        int n,foo[202],dp[202]={0};
        char str[202];
        in_I(n);
        scanf("%s",str+1);
        foo[0]=0;
        for(int i=1;i<=n;i++)
        {
            foo[i]=foo[i-1]+(str[i]=='1');
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(foo[i]-foo[j]>(i-j)/2)
                dp[i]=max(dp[i],dp[j]+(i-j));
                else
                dp[i]=max(dp[i],dp[j]);
            }
        }
        cout<<dp[n]<<endl;
    }
}

