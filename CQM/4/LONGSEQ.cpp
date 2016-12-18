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
int n;
int dp[1000001];
int getans(int n)
{
    if(dp[n])
        return dp[n];
    if(n/10 == 0)
        return 1;
    int len = 0;
    int &ret = dp[n];
    int n2 = n;
    vector<int> dig;
    while(n2)
    {
        dig.push_back(n2%10);
        len++, n2/=10;
    }
    reverse(dig.begin(), dig.end());
    for(int i  = 1;i<(1<<len);i++)
    {
        int prod = 1;
        int tmp = 0;
        for(int j = 0;j<dig.size();j++)
        {
            if(tmp == -1)tmp = 0;
            tmp = tmp*10 + dig[j];
            if(i&(1<<j))
                prod *= tmp, tmp = -1;
        }
        if(tmp>=0)
            prod*=tmp;
        if(prod != n)
            ret = max(ret, 1+getans(prod));
    }
    return ret;
}
int main()
{
    in_T
    {
        in_I(n);
        printf("%d\n", getans(n));
    }
}
