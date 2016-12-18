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
#include<cstring>
#include<cstdlib>
#include<cassert>
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
struct res{long long a[6];};res dp[20][11];

res getans(long long x, int idx, int carry)
{
    if(x == carry)
    {
        res x;
        for(int i = 0; i<6;i++)
            x.a[i] = 0;
        return x;
    }
    if(x == 0)
    {
        res x;
        x.a[0] = -1;
        return x;
    }
    if(dp[idx][carry].a[0] != -1)
    {
        return dp[idx][carry];
    }
    res &ans = dp[idx][carry];
    for(int i = 0; i<=6;i++)
    {
        for(int j = 0; i+j<=6; j++)
        {
            int cur = 7*i + j*4 + carry;
            if(x%10 == cur%10)
            {
                res res2 = getans(x/10, idx+1, cur/10);
                if(res2.a[0] != -1)
                {
                    int c = 0;
                    while(c<i)
                    {
                        ans.a[c] = res2.a[c]*10 + 7;
                        c++;
                    }
                    while(c<i+j)
                    {
                        ans.a[c] = res2.a[c]*10 + 4;
                        c++;
                    }
                    while(c<6)
                    {
                        ans.a[c] = res2.a[c]*10;
                        c++;
                    }
                    return ans;
                }
            }
        }
    }
    return ans;
}
void solve(long long x)
{
    for(int i = 0; i<20;i++)
        for(int j = 0 ;j<11;j++)
        dp[i][j].a[0] = -1;
    res r = getans(x, 0, 0);
    if(r.a[0] != -1)
    {
        for(int i = 0 ;i<6;i++)
            printf("%lld ", r.a[i]);
        newline;
    }
    else
        cout<<-1<<endl;
}
int main()
{
    in_T
    {
        long long n;
        in_L(n);
        solve(n);
    }
}
