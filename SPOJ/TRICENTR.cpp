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
    in_T
    {
        double a, c_a, c_b, c_c;
        cin>>a>>c_a>>c_b>>c_c;
        double area = (3*a*c_a)/2;
        printf("%.3lf ", area);
        double b = (2*area)/(3*c_b);
        double c = (2*area)/(3*c_c);
        double r = (a*b*c)/(4*area);
        double foo = 9*r*r-a*a-b*b-c*c;
        if(foo<0.0f)foo = 0.0f;
        printf("%.3lf\n", (2*sqrt(foo))/3);
//        double xx = sqrt((c_a*c_a)*(a*a/(c_b*c_b) - 9));
//        double yy = 3*c_a;
//        double m1 = -xx/yy;
//        double x1 = xx, y1 = m1*(x1-a);
//        double x2 = (xx+a)/3, y2 = c_a;
//        printf("%.3lf\n", sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)));
    }
}
