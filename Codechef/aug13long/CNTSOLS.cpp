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
int ETF[41] = {0 ,1 ,1 ,2 ,2 ,4 ,2 ,6 ,4 ,6 ,4 ,10 ,4 ,12 ,6 ,8 ,8 ,16 ,6 ,18 ,8 ,12 ,10 ,22 ,8 ,20 ,12 ,18 ,12 ,28 ,8 ,30 ,16 ,20 ,16 ,24 ,12 ,36 ,18 ,24 ,16};
int upper, d,m, N;
int mod = 1000000007;
int POW(long long r, long long n, int mod)
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
    in_T
    {
        in_I(upper);in_I(d);in_I(m);in_I(N);
        long long ans = 0;
        int base = (upper)/N;

        for(int x1 = 0; x1<min(N, upper+1); x1++)
        {
            long long poss1 = base + (x1<=upper%N);
            for(int x2 = 0; x2 < min(N, upper+1); x2++)
            {
                long long poss2 = base + (x2<=upper%N);
                for(int x3 = 0; x3<min(upper+1, N); x3++)
                {
                    long long poss3 = base + (x3<=upper%N);
//                    cout<<x1<<" "<<x2<<" "<<x3<<endl;
//                    cout<<poss1<<" "<<poss2<<" "<<poss3<<endl;
                    int sol1 = POW(x1, d, N);
                    int sol2 = POW(x2, d, N);
                    int sol3 = POW(x3, d, N);

//                    cout<<sol1<<" "<<sol2<<" "<<sol3<<endl<<endl;
                    if((sol1 + sol2 + sol3)%N == m)
                        ans = (ans + (((poss1*poss2)%mod)*poss3)%mod)%mod;
                }
            }
        }
        cout<<ans<<endl;
    }
}
