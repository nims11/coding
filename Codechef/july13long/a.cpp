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
typedef pair<int, int> PT;
typedef pair<double, double> PTD;
PT p[50];
typedef struct foo{
    double a, b, c;
    foo(double x, double y, double z):a(x),b(y),c(z){}
} LINE;

PTD LL_intersect(LINE L1, LINE L2)
{
    double det = L1.a*L2.b - L1.b*L2.a;
    // Assuming det != 0
    return make_pair((L2.b*L1.c - L1.b*L2.c)/det, (L1.a*L2.c - L2.a*L1.c)/det);
}
PTD get_CC(int p1, int p2, int p3)
{
    double a1 = p[p2].first - p[p1].first,
           b1 = p[p2].second - p[p1].second,
           a2 = p[p3].first - p[p2].first,
           b2 = p[p3].second - p[p2].second;
    PTD pp1 = make_pair((p[p1].first+p[p2].first)/2.0, (p[p1].second+p[p2].second)/2.0),
        pp2 = make_pair((p[p2].first+p[p3].first)/2.0, (p[p2].second+p[p3].second)/2.0);
    LINE L1(a1, b1, a1*pp1.first+b1*pp1.second), L2(a2, b2, a2*pp2.first+b2*pp2.second);
    return LL_intersect(L1, L2);
}
inline bool chk(int p1, int p2, int p3)
{
    return (p[p2].second-p[p1].second)*(p[p3].first-p[p1].first) != (p[p3].second - p[p1].second)*(p[p2].first - p[p1].first);
}
inline double dist(PTD p1, PTD p2)
{
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}
int main()
{
    in_T
    {
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
            scanf("%d%d", &p[i].first, &p[i].second);
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
                    PTD cc = get_CC(i, j, k);
                    double rad = dist(cc, p[i]);
                    for(int l = 0; l<n; l++)
                    {
                        if(l != i && l!=j && l!=k)
                        {
                            if(dist(p[l], cc) <= rad)
                            {
//                                cout<<rad<<" "<<cc.first<<" "<<cc.second<<endl;
//                                cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                                cnt++;
                            }
                        }
                    }
                }
        printf("%.6lf\n",double(cnt)/tot);
    }
}
