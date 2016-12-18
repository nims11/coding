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
int main()
{
    long long n,d,c,m;
    while(cin>>n>>d>>c>>m)
    {
        n *= m;
        d *= m;
        c *= m;
        double thr = c/3.0;
        if(thr>d)
            thr = d;
        double per_gain = c - d + thr;
        double per_loss = 2*c;
        double ans = 0;
        if(per_gain<=d)
        {
            ans = per_gain;
        }
//        if(per_gain>d)
//        {
//            while(n>0)
//            {
//                ans += per_gain-d;
//                n -= per_loss+c;
//            }
//            ans += d;
//        }
        if(ans>0)
        {
            printf("%.0lf\n", ans);
        }else
            cout<<0<<endl;
    }
}
