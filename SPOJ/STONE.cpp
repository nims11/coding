/*
    Nimesh Ghelani (nims11)
    divide the the polygon into triangles. find their COG(centroid) and area. and use the eq
    x = (A1*x1 + A2*x2 + ... ) / (A1 + A2)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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
class POINT
{
    public:
    int P[2];
};

POINT operator-(const POINT &a,const POINT &b)
{
    POINT foo;
    foo.P[0] = a.P[0] - b.P[0];
    foo.P[1] = a.P[1] - b.P[1];
    return foo;
}
int operator^(const POINT &a, const POINT &b)
{
    return a.P[0]*b.P[1] - a.P[1]*b.P[0];
}
POINT points[1000000];
int N;
int main()
{
    in_T
    {
        in_I(N);
        for(int i=0;i<N;i++)
            scanf("%d%d", &points[i].P[0], &points[i].P[1]);
        double pre_area = 0,curr_area;
        double x = 0;
        double y = 0;
        for(int i=2;i<N;i++)
        {
            curr_area = (points[i-1]-points[0])^(points[i]-points[0]);
            x += curr_area*(points[0].P[0]+points[i-1].P[0]+points[i].P[0]);
            y += curr_area*(points[0].P[1]+points[i-1].P[1]+points[i].P[1]);
            pre_area+=curr_area;
        }
        printf("%.2lf %.2lf\n", x/(3*pre_area), y/(3*pre_area));
    }
}
