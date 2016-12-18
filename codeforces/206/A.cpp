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
int n, l, r, Ql, Qr;
int main()
{
    cin>>n>>l>>r>>Ql>>Qr;
    int w[n+1], w_sum[n+1];
    w_sum[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        in_I(w[i]);
        w_sum[i] = w_sum[i-1] + w[i];
    }
    long long ans = 100000000000000000LL;
    for(int i = 0; i<=n; i++)
    {
        int l_tot = i, r_tot = n-i;
        long long cur = 0;
        if(r_tot > l_tot)
        {
            cur += w_sum[l_tot]*1LL*l + (w_sum[n]-w_sum[n-l_tot-1])*1LL*r + (w_sum[n-l_tot-1]-w_sum[l_tot])*1LL*r + (n-l_tot-1-l_tot)*1LL*Qr;
        }else if(r_tot < l_tot)
        {
            cur += w_sum[r_tot+1]*1LL*l + (w_sum[n]-w_sum[n-r_tot])*1LL*r + (w_sum[l_tot]-w_sum[r_tot+1])*1LL*l + (l_tot-r_tot-1)*1LL*Ql;
        }else
        {
            cur += w_sum[r_tot]*1LL*l + (w_sum[n]-w_sum[n-r_tot])*1LL*r;
        }
        ans = min(ans, cur);
    }
    cout<<ans<<endl;
}
