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
long long arr[100000];
inline long long solve()
{
    long long ret = 0;
    long long pow_2 = 1;
    for(int i = 0;i<31;i++, pow_2<<=1)
    {
        bool one = false;
        long long tot[2] = {0};
        bool cur = false;
        long long res = 0;
        for(int j = 0;j<n;j++)
        {
            tot[cur]++;
            if(arr[j]&(1<<i))
            {
                one = true;
                res += tot[cur];
                cur ^= 1;
            }else
            {
                res+=tot[!cur];
            }
        }
        ret += pow_2*res;
    }
    return ret;
}
int main()
{
    in_T
    {
        in_I(n);
        for(int i = 0;i<n;i++)
            in_L(arr[i]);
        printf("%lld\n", solve());
    }
}
