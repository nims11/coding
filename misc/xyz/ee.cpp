#include<bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
using namespace std;
template <class T>
class POINT3
{
    public:
    T P[3];
    POINT3(){};
    POINT3(T x, T y, T z){P[0] = x, P[1] = y, P[2] = z;}
};
template <class T>
double dist(const POINT3<T> &a, const POINT3<T> &b)
{
    T d1 = a.P[0]-b.P[0];
    T d2 = a.P[1]-b.P[1];
    T d3 = a.P[2]-b.P[2];
    return d1*d1 + d2*d2 + d3*d3;
}
int x[2], y[2], z[2], r[2], vx[2], vy[2], vz[2];
int r_sqr;
double get_t(){
    int x1 = x[0] - x[1];
    int y1 = y[0] - y[1];
    int z1 = z[0] - z[1];
    int vx1 = vx[0] - vx[1];
    int vy1 = vy[0] - vy[1];
    int vz1 = vz[0] - vz[1];
    long long sum_vx = vx1*vx1 + vy1*vy1 + vz1*vz1;
    long long sum_vx_x = vx1*x1 + vy1*y1 + vz1*z1;
    long long sum_x = x1*x1 + y1*y1 + z1*z1;

    pair<long long, long long> closest_d;
    closest_d.second = sum_vx;
    closest_d.first = sum_x*sum_vx - sum_vx_x*sum_vx_x;
    if(r_sqr*closest_d.second < closest_d.first)
        return -1;

    return -(sum_vx_x)/double(sum_vx);
}
int main()
{
    in_T{
        for(int i = 0;i<2;i++){
            scanf("%d%d%d%d%d%d%d", &x[i], &y[i], &z[i], &r[i], &vx[i], &vy[i], &vz[i]);
        }
        r_sqr = (r[0]+r[1])*(r[0]+r[1]);
        double closest_t = get_t();
        if(closest_t < 0){
            printf("No collision\n");
            continue;
        }else{
            
        }

        POINT3<double> p1(x[0], y[0], z[0]);
        POINT3<double> p2(x[1], y[1], z[1]);
        double cur_time = closest_t;
        p1.P[0] += cur_time*vx[0];
        p1.P[1] += cur_time*vy[0];
        p1.P[2] += cur_time*vz[0];
        p2.P[0] += cur_time*vx[1];
        p2.P[1] += cur_time*vy[1];
        p2.P[2] += cur_time*vz[1];
        double iteration = 0.005;
        double d = dist(p1, p2);
        for(; cur_time>0; cur_time -= iteration){
            p1.P[0] -= iteration*vx[0];
            p1.P[1] -= iteration*vy[0];
            p1.P[2] -= iteration*vz[0];
            p2.P[0] -= iteration*vx[1];
            p2.P[1] -= iteration*vy[1];
            p2.P[2] -= iteration*vz[1];
            double d2 = dist(p1, p2);
            if(d2 > r_sqr){
                break;
            }
            d = d2;
        }
        printf("%.3lf\n", cur_time);
    }
}
