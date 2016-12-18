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
template <class T>
class POINT3
{
    public:
    T P[3];
    POINT3(){};
    POINT3(T x, T y, T z){P[0] = x, P[1] = y, P[2] = z;}
    //dot
    T operator*(const POINT3 &a)
    {
        return a.P[0]*this->P[0] + a.P[1]*this->P[1] + a.P[2]*this->P[2];
    }
    POINT3 operator-(const POINT3 &b)
    {
        return POINT3(this->P[0] - b.P[0], this->P[1] - b.P[1], this->P[2] - b.P[2]);
    }
    //cross
    POINT3 operator^(const POINT3 &b)
    {
        return POINT3(this->P[1]*b.P[2] - b.P[1]*this->P[2],
                     b.P[0]*this->P[2] - this->P[0]*b.P[1],
                     this->P[0]*b.P[1] - b.P[0]*this->P[1]);
    }
};
template <class T>
double dist(const POINT3<T> &a, const POINT3<T> &b)
{
    T d1 = a.P[0]-b.P[0];
    T d2 = a.P[1]-b.P[1];
    T d3 = a.P[2]-b.P[2];
    return sqrt(d1*d1 + d2*d2 + d3*d3);
}
int main()
{
    in_T{
        int x[2], y[2], z[2], r[2], vx[2], vy[2], vz[2];
        for(int i = 0;i<2;i++){
            cin>>x[i]>>y[i]>>z[i]>>r[i]>>vx[i]>>vy[i]>>vz[i];
        }
        POINT3<double> p1(x[0], y[0], z[0]);
        POINT3<double> p2(x[1], y[1], z[1]);
        int cur_time = 0;
        double d = dist(p1, p2);
        bool trend = false;
        double collide_time = -1;
        for(cur_time = 1; cur_time < 200;cur_time++){
            p1.P[0] += cur_time*vx[0];
            p1.P[1] += cur_time*vy[0];
            p1.P[2] += cur_time*vz[0];
            p2.P[0] += cur_time*vx[1];
            p2.P[1] += cur_time*vy[1];
            p2.P[2] += cur_time*vz[1];
            double d2 = dist(p1, p2);
            if(d2 < d){
                trend = true;
            }
            
            if((d2 >=  d && trend) || d2 <= r[0]+r[1]){
                cur_time--;
                p1.P[0] -= cur_time*vx[0];
                p1.P[1] -= cur_time*vy[0];
                p1.P[2] -= cur_time*vz[0];
                p2.P[0] -= cur_time*vx[1];
                p2.P[1] -= cur_time*vy[1];
                p2.P[2] -= cur_time*vz[1];
                collide_time = cur_time;
                for(;;collide_time+=0.09){
                    d2 = dist(p1, p2);
                    if(d2 <= r[0]+r[1])
                        break;
                    }
                break;
            }
        }
        if(collide_time < 0){
            printf("impossible\n");
        }else{
            printf("%.2lf\n", collide_time);
        }
    }
}
