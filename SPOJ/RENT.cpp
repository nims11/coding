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
struct job
{
    int start, end, profit;
    friend bool operator<(const job &a, const job &b)
    {
        return a.end<b.end;
    }
}jobs[10002], tmp;
int n;
int dp[20000];
int main()
{
    jobs[0].start = jobs[0].end = jobs[0].profit= 0;
    in_T
    {
        in_I(n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d", &jobs[i].start, &jobs[i].end, &jobs[i].profit);
            jobs[i].end += jobs[i].start;
        }
        sort(jobs+1, jobs+1+n);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            tmp.end = jobs[i].start;
            dp[i] = max(dp[i-1], dp[int(lower_bound(jobs, jobs+i, tmp)-1-jobs)] + jobs[i].profit);
        }
        printf("%d\n", dp[n]);
    }
}
