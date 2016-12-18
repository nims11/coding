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
#define newline prlong longf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {long long tmp=a;a=b;b=tmp;}
#define P_I(a) prlong longf("%d",a)

using namespace std;
typedef pair<long long, long long> PT;
PT p[50];
typedef struct foo{
    long long a, b, c;
    foo(long long x, long long y, long long z):a(x),b(y),c(z){}
} LINE;

pair<pair<long long, long long>, long long> LL_intersect(LINE L1, LINE L2)
{
    long long det = L1.a*L2.b - L1.b*L2.a;
    // Assuming det != 0
    return make_pair(make_pair((L2.b*L1.c - L1.b*L2.c), (L1.a*L2.c - L2.a*L1.c)), det);
}
pair<pair<long long, long long>, long long> get_CC(int p1, int p2, int p3)
{
    long long a1 = p[p2].first - p[p1].first,
           b1 = p[p2].second - p[p1].second,
           a2 = p[p3].first - p[p2].first,
           b2 = p[p3].second - p[p2].second;
    PT pp1 = make_pair((p[p1].first+p[p2].first), (p[p1].second+p[p2].second)),
       pp2 = make_pair((p[p2].first+p[p3].first), (p[p2].second+p[p3].second));
    LINE L1(2*a1, 2*b1, a1*pp1.first+b1*pp1.second), L2(2*a2, 2*b2, a2*pp2.first+b2*pp2.second);
    return LL_intersect(L1, L2);
}
inline bool chk(int p1, int p2, int p3)
{
    return (p[p2].second-p[p1].second)*(p[p3].first-p[p1].first) != (p[p3].second - p[p1].second)*(p[p2].first - p[p1].first);
}
int main()
{
    in_T
    {
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
            scanf("%lld%lld", &p[i].first, &p[i].second);
        int tot = 0;
        int cnt = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    tot += n-3;
                    if(chk(i, j, k) == 0)
                    {
                        continue;
                    }
                    pair<pair<long long, long long>, long long> cc = get_CC(i, j, k);
                    long long d = cc.second;
                    PT c = cc.first;
                    long long rad_2 = (c.first-p[i].first*d)*(c.first-p[i].first*d)+(c.second-p[i].second*d)*(c.second-p[i].second*d);
//                    if(!t)
//                    {
//                        cout<<i<<" "<<j<<" "<<k<<endl;
//                        cout<<c.first<<" "<<c.second<<" "<<sqrt(rad_2)<<endl;
//                    }
                    for(int l = 0; l<n; l++)
                    {
                        if(l != i && l!=j && l!=k)
                        {
                            if((c.first-p[l].first*d)*(c.first-p[l].first*d)+(c.second-p[l].second*d)*(c.second-p[l].second*d) <= rad_2)
                            {
                                cnt++;
                            }
                        }
                    }
//                    if(!t)
//                    {
//                        cout<<cnt<<endl;
//                        newline;
//                    }
                }
        printf("%.6lf\n",double(cnt)/tot);
    }
}
