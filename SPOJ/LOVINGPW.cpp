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
const long long mod = 1000000007;
long long case1(long long n, int pos)
{
    long long x = n>>(pos+1);
    long long y = n^((x<<(pos+1))|(1LL<<pos));
    long long ret = (x<<pos)|y;
    return ret+1;
}
long long case0(long long n, int pos)
{
    long long x = n>>(pos+1);
    long long y = n^((x<<(pos+1)));
    long long ret = (x<<pos)|y;
//    cout<<" "<<ret<<endl;
    ret -= y+1;
//    cout<<" "<<ret<<endl;
    return ret+1;
}
int main()
{
//    cout<<case0(107, 3)<<endl;
    in_T
    {
        long long n;
        in_L(n);
        long long ans = 0;
        for(int i=0;i<62;i++)
        {
            if(n&(1LL<<i))
            {
                ans = (ans+case1(n, i))%mod;
            }
            else
                ans = (ans+case0(n, i))%mod;
//            cout<<ans<<endl;
        }
//        int yy = 0;
//        for(int i=0;i<=n;i++)
//            for(int j=0;j<=n;j++)
//        {
//            for(int k=0;(1<<k)<=n;k++)
//                if(((1<<k)^(i^j)) == 0){yy++;break;}
//        }
//        cout<<yy/2<<endl;
        printf("%lld\n", ans);
    }
}
