#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;
inline long long sqr(long long a){return a*a;}
inline double sqr(double a){return a*a;}
inline double dist(double x1, double y1, double x2, double y2){
    return (sqr(x1-x2) + sqr(y1-y2));
}
int main(){
    long long R, x1, y1, x2, y2;
    cin>>R>>x1>>y1>>x2>>y2;
    if(sqr(x2-x1) + sqr(y2-y1) >= sqr(R)){
        printf("%.8lf %.8lf %.8lf\n", (double)x1, (double)y1, (double)R);
        return 0;
    }
    long long orig_x = x1;
    long long orig_y = y1;
    x2 -= x1;
    y2 -= y1;
    x1 -= x1;
    y1 -= y1;

    long double xx1, xx2, yy1, yy2;
    if(x1 == x2 && y2 == y1){
        xx1 = R;
        yy1 = 0;
    }else if(x1 == x2){
        xx1 = 0;
        xx2 = 0;
        yy1 = R;
        yy2 = -R;
        if(dist(xx1, yy1, x2, y2) < dist(xx2, yy2, x2, y2)){
            swap(xx1, xx2);
            swap(yy1, yy2);
        }
    }else if(y1 == y2){
        xx1 = R;
        xx2 = -R;
        yy1 = 0;
        yy2 = 0;
        if(dist(xx1, yy1, x2, y2) < dist(xx2, yy2, x2, y2)){
            swap(xx1, xx2);
            swap(yy1, yy2);
        }
    }else{
        long double m = y2/(double)x2;
        xx1 = sqrt(R*R/(1+m*m));
        xx2 = -xx1;
        yy1 = sqrt(R*R - xx1*xx1);
        yy2 = -yy1;
        if(abs(xx1*y2 - x2*yy1) > 1e-6)
            swap(xx1, xx2);
        if(dist(xx1, yy1, x2, y2) < dist(xx2, yy2, x2, y2)){
            swap(xx1, xx2);
            swap(yy1, yy2);
        }
    }
    long double ax = (xx1+x2)/2;
    long double ay = (yy1+y2)/2;
    long double ar = sqrt(dist(ax, ay, x2, y2));
    printf("%.10Lf %.10Lf %.10Lf\n", ax+orig_x, ay + orig_y, ar);
}
