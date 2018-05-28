#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;

using namespace std;

const double eps = 1e-7;
int main(){
    double pi = acos(-1);
    double cc = atan(sqrt(2));
    int z = 0;
   in_T{
       z++;
       double A;
       in_F(A);
       double rad1 = 0, rad2 = 0;
       if(A * A <= 2 + eps){
           rad1 = pi/4 - abs(acos(A / sqrt(2)));
       }else{
           rad1 = pi/4;
           double st = 0, end = 0.62;
           while(true){
               double mid = (st + end)/2;
               double area = (cos(mid) + sqrt(3) * cos(cc - mid))/sqrt(2);
               if(abs(area - A) < eps){
                   rad2 = mid;
                   break;
               }else if(area > A){
                   end = mid;
               }else
                   st = mid;
           }
       }
       printf("Case #%d:\n", z);
       double x1 = 0.5, y1 = 0, z1 = 0;
       double x2 = 0, y2 = 0.5, z2 = 0;
       double x3 = 0, y3 = 0, z3 = 0.5;

       // rotate along x with rad1
       y2 = 0.5*cos(rad1);
       z2 = 0.5*sin(rad1);
       y3 = -0.5*sin(rad1);
       z3 = 0.5*cos(rad1);

       // rotate along z with rad2
       double tmp1, tmp2;
       tmp1 = x1 * cos(rad2) - y1 * sin(rad2);
       tmp2 = x1 * sin(rad2) + y1 * cos(rad2);
       x1 = tmp1; y1 = tmp2;
       tmp1 = x2 * cos(rad2) - y2 * sin(rad2);
       tmp2 = x2 * sin(rad2) + y2 * cos(rad2);
       x2 = tmp1; y2 = tmp2;
       tmp1 = x3 * cos(rad2) - y3 * sin(rad2);
       tmp2 = x3 * sin(rad2) + y3 * cos(rad2);
       x3 = tmp1; y3 = tmp2;


       printf("%.10lf %.10lf %.10lf\n", x1, y1, z1);
       printf("%.10lf %.10lf %.10lf\n", x2, y2, z2);
       printf("%.10lf %.10lf %.10lf\n", x3, y3, z3);
       /* cout<<rad1<<" "<<rad2<<endl; */
   }
}
