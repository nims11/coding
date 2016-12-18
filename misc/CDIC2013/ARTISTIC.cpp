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
long long n, X1, X2, Y1, Y2, ax,bx,ay,by;
double x, y;
bool is_valid(double x, double y)
{
    return x>=X1 && x<=X2 && y>=Y1 && y<=Y2;
}
bool is_valid(pair<double, double> P)
{
    return P.first>=X1 && P.first<=X2 && P.second>=Y1 && P.second<=Y2;
}
bool is_valid()
{
    return !((ax>X2 && bx>X2) || (ax<X1 && bx<X1) || (ay>Y2 && by>Y2) || (ay<Y1 && by<Y1));
}
int main()
{
    in_T
    {
        scanf("%lld%lld%lld%lld%lld", &X1, &Y1, &X2, &Y2, &n);
        while(n--)
        {
            scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
            long long A = by-ay, B = ax - bx, C = ay*(bx-ax)-ax*(by-ay);
            int cnt = 0;
            pair<double, double> pts[2], PT[2] = {make_pair(ax, ay), make_pair(bx, by)};

            // x = X1
            x = X1;
            y = (X1*double(A) + C)/(-B);
            if(is_valid(x, y))
            {
                pts[cnt++] = make_pair(x, y);
            }
            if(cnt == 2)
                goto print;

            // x = X2
            x = X2;
            y = (X2*double(A) + C)/(-B);
            if(is_valid(x, y))
            {
                pts[cnt++] = make_pair(x, y);
            }
            if(cnt == 2)
                goto print;

            // y = Y1
            x = (Y1*double(B) + C)/(-A);
            y = Y1;
            if(is_valid(x, y))
            {
                pts[cnt++] = make_pair(x, y);
            }
            if(cnt == 2)
                goto print;

            // y = Y2
            x = (Y2*double(B) + C)/(-A);
            y = Y2;
            if(is_valid(x, y))
            {
                pts[cnt++] = make_pair(x, y);
            }
            if(cnt == 2)
                goto print;

            print:
                if(cnt == 2 && is_valid())
                {
                    if(pts[0]>pts[1])
                        swap(pts[0], pts[1]);
                    if(pts[0] < min(PT[0], PT[1]) && is_valid(min(PT[0], PT[1])))
                        pts[0] = min(PT[0], PT[1]);
                    if(pts[1] > max(PT[0], PT[1]) && is_valid(max(PT[0], PT[1])))
                        pts[1] = max(PT[0], PT[1]);

                    printf("%.6lf %.6lf %.6lf %.6lf\n", pts[0].first, pts[0].second, pts[1].first, pts[1].second);
                }else
                {
                    printf("OUTSIDE\n");
                }
        }
    }
}
