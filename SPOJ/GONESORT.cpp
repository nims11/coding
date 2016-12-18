/*
    Nimesh Ghelani (nims11)
    Find the Longest consecutive subsequence
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
int arr1[300],arr2[300];
int dp[300];
int main()
{
    in_T
    {
        int b;
        in_I(b);
        for(int i=0;i<b;i++)
        {
            in_I(arr1[i]);
            arr2[i] = arr1[i];
        }
        sort(arr2,arr2+b);
        for(int i=0;i<b;i++)
            dp[i]=1;
        map<int,int> foo;
        for(int i =0;i<b;i++)
            foo[arr2[i]] = i;
        for(int i=0;i<b;i++)
            arr1[i] = foo[arr1[i]];
        int ans = 1;
        for(int i=1;i<b;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr1[j]+1 == arr1[i])
                {
                    dp[i]+=dp[j];
                    break;
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n",b-ans);
    }
}
