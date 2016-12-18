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
    int c=0;
    in_T
    {
        c++;
        int arr[102];
        int sum=0,sum2;
        int dp[51000];
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
        {
            in_I(arr[i]);
            sum+=arr[i];
        }
        sum2=sum;
        sum/=2;
        for(int i=1;i<=sum;i++)
        dp[i]=0;
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=sum;j>=0;j--)
            if(j-arr[i]>=0)
            dp[j]=(dp[j]+dp[j-arr[i]])%7777777;

//            for(int j=0;j<=sum;j++)
//            cout<<dp[j]<<" ";
//            cout<<endl;
        }
        int i;
        for(i=sum;i>=0 && dp[i]==0;i--);
        if(sum%2==0 && i==sum/2)
        cout<<"Case #"<<c<<": "<<(sum2-2*i)<<" "<<dp[i]<<endl;
        else
        cout<<"Case #"<<c<<": "<<(sum2-2*i)<<" "<<(2*dp[i])%7777777<<endl;
    }
}
