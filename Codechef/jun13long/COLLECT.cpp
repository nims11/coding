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
int BIT[100001];
int n, tmp, q;
char str[10], l, r;
int query(int idx)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
void update(int idx, int val)
{
    while(idx<=n)
    {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}
const int mod = 1e9+7;
long long fact[3000001];
int arr[100001];
int inv[100005];
int POW(long long r, int n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int main()
{
    fact[0] = fact[1] = 1;
    for(int i=2;i<=3000000;i++)
        fact[i] = (fact[i-1]*i)%mod;
    for(int i=0;i<100005;i++)
        inv[i] = POW(fact[i], mod-2);
    cout<<inv[4]<<endl;
    in_I(n);
    for(int i=1;i<=n;i++)
    {
        in_I(arr[i]);
        update(i, arr[i]);
    }
    in_I(q);
    while(q--)
    {
        scanf("%s%d%d", str, &l, &r);
        if(str[0] == 'c')
        {
            update(l, r-arr[l]);
            arr[l] = r;
        }else
        {
            long long ans = query(r)-query(l-1);
            tmp = ans/(r-l+1);
            int ex = ans%(r-l+1);
            ans = (fact[r-l+1]*fact[ans])%mod;
            ans = (ans*POW(inv[tmp], r-l+1-ex))%mod;
            ans = (ans*POW(inv[tmp+1], ex))%mod;
            ans = (((ans*inv[ex])%mod)*inv[r-l+1-ex])%mod;
//            cout<<ans<<endl;
            printf("%lld\n", ans);
        }
    }
}
