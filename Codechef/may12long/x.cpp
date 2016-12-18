#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
        int t,n;
        scanf("%d",&t);
        while(t--)
        {
                long long a[31];
                scanf("%d",&n);
                for(int i=0;i<n;i++)scanf("%lld",&a[i]);
                sort(a,a+n);
                int dp[31]={0};
                for(int i=1;i<n;i++)
                        if(a[i]!=a[i-1])dp[i]=dp[i-1]+1;
                        else dp[i]=dp[i-1];
                printf("%d\n",dp[n-1]);
        }
        return 0;
}
