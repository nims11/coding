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
long long pow_10[11];
long long mod = 1000000007;
long long sum(long long n)
{
    long long x = n, y = n+1;
    if(x%2 == 0)x/=2;
    else y/=2;
    x %= mod;
    y %= mod;
    return (x*y)%mod;
}
long long till_end(int n, int len)
{
    long long ret = (sum(pow_10[len]-1)-sum(n-1))%mod;
    if(ret<0)
        ret+=mod;
    return ret;
}
long long from_start(int n, int len)
{
    long long ret = (sum(n)-sum(pow_10[len-1]-1))%mod;
     if(ret<0)
        ret+=mod;
    return ret;
}
int main()
{
    pow_10[0] = 1;
    for(int i  =1;i<=10;i++)
        pow_10[i] = (pow_10[i-1]*10);
    in_T
    {
        int L, R;
        in_I(L);in_I(R);
        long long res = 0;
        int len1 = 0, len2 = 0;
        long long l1 = L, r2 = R;
        while(l1)
        {
            l1/=10;len1++;
        }
        while(r2)
        {
            r2/=10;len2++;
        }
        if(len1 == len2)
        {
            res = sum(R)-sum(L-1);
            res %= mod;
            if(res<0)
                res+=mod;
            res = (res*len1)%mod;
        }else
        {
            res = (till_end(L, len1)*len1)%mod;
            res = (res + ((from_start(R, len2)*len2)%mod))%mod;
            for(int i = len1+1;i<len2;i++)
            {
                long long tmp = (((sum(pow_10[i]-1)-sum(pow_10[i-1]-1))*i)%mod);
                if(tmp<0)
                    tmp+=mod;
                res = (res + tmp)%mod;
            }
        }
        printf("%lld\n", res);
    }
}
