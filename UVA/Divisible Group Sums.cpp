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
int main()
{
    int t=0;
    int n,q,d,m;
    int dp[11][201][21];
    while(cin>>n>>q)
    {
        if(n==0)return 0;
        t++;
        printf("SET %d:\n", t);
        int arr[n];
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        for(int z=1;z<=q;z++)
        {
            printf("QUERY %d: ", z);
            in_I(d);in_I(m);
            for(int i=1;i<=m;i++)
            {
                for(int j=0;j<n;j++)
                    for(int k=0;k<d;k++)
                        dp[i][j][k] = 0;
            }
            for(int j=0;j<n;j++)
            {
                dp[1][j][(arr[j]%d+d)%d]++;
            }
            for(int i=2;i<=m;i++)
            {
                for(int j=i-1;j<n;j++)
                {
                    for(int j2=i-2;j2<j;j2++)
                    {
                        for(int k=0;k<d;k++)
                        dp[i][j][((k+arr[j])%d+d)%d] += dp[i-1][j2][k];
                    }
                }
            }
            int ans=0;
            for(int j=m-1;j<n;j++)
                ans+=dp[m][j][0];
            printf("%d\n", ans);
        }
    }
}
