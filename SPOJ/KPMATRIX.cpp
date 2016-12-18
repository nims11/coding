/*
    Nimesh Ghelani (nims11)
    O(n^2*m*lg(m))
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
#include<set>
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

int z;
int BIT[300];
void update(int idx)
{
	while(idx<=z)
	{
		BIT[idx]++;
		idx+=(idx & -idx);
	}
}
int query(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=BIT[idx];
		idx -= (idx & -idx);
	}
	return ans;
}
int dp[252][252];
int arr[300];
const int INF = 2000000003;

int main()
{
    int n,m,x;
    in_I(n);
    in_I(m);
    for(int i=0;i<=m;i++)
        dp[0][i] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            in_I(x);
            dp[i][j] = dp[i-1][j]+x;
        }
    }

    int a,b;
    in_I(a);in_I(b);
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int sum = 0;
            int sz = 1;
            for(int k=0;k<=m;k++)
                arr[sz++]=(sum+=(dp[j][k]-dp[i-1][k]));

            arr[sz++] = INF;
            arr[sz++] = -INF;

            z = sz;
            sort(arr+1, arr+sz);

            for(int k=0;k<=z;k++)
                BIT[k] = 0;

            update(int(lower_bound(arr+1, arr+sz, 0) - arr));
            sum = 0;
            for(int k=1;k<=m;k++)
            {
                sum+=(dp[j][k]-dp[i-1][k]);
                ans += -query(int(lower_bound(arr+1, arr+sz, sum-b)-arr)-1)+query(int(upper_bound(arr+1, arr+sz, sum-a)-arr)-1);
                update(int(lower_bound(arr+1, arr+sz, sum)-arr));
            }
        }
    }
    printf("%d\n", ans);
}

