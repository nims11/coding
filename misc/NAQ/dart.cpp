#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
template <class T>
class POINT{
    public:
    T P[2];
    POINT(){}
    POINT(T x, T y){P[0] = x, P[1] = y;}
    //dot
    T operator*(const POINT &a){
        return a.P[0]*this->P[0] + a.P[1]*this->P[1];
    }
    POINT operator-(const POINT &b){
        return POINT(this->P[0] - b.P[0], this->P[1] - b.P[1]);
    }
    //cross
    T operator^(const POINT &b){
        return this->P[0]*b.P[1] - this->P[1]*b.P[0];
    }
};
// sign of ba x ca
int ccw(POINT<long long> a, POINT<long long> b, POINT<long long> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
// If a-b intersects with c-d
bool intersect(POINT<long long> a, POINT<long long> b, POINT<long long> c, POINT<long long> d)
{
    if(ccw(a,b,c) == 0 && ccw(a,b,d) == 0){
        if((((b-a)*(c-b))>0 && ((b-a)*(d-b))>0) || (((a-b)*(c-a))>0 && ((a-b)*(d-a))>0))
            return false;
        else
            return true;
    }
    return ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d);
}
int tmp[7];
int perms[6000][7];
int perm_cnt;
POINT<long long> pts[7];
bool invalid(int pidx){
    for(int i = 1;i<7;i++){
        for(int j = i+2;j<7;j++)
            if(intersect(pts[perms[pidx][i]-1], pts[perms[pidx][i-1]-1], pts[perms[pidx][j]-1], pts[perms[pidx][j-1]-1]))
                return true;
    }
    for(int j = 2;j<6;j++)
        if(intersect(pts[perms[pidx][0]-1], pts[perms[pidx][6]-1], pts[perms[pidx][j]-1], pts[perms[pidx][j-1]-1]))
            return true;
    return false;
}
int main(){
    for(int i = 0;i<7;i++)
        tmp[i] = i+1;
    do{
        for(int i = 0;i<7;i++)
            perms[perm_cnt][i] = tmp[i];
        perm_cnt++;
    }while(next_permutation(tmp, tmp+7));
    in_T{
        for(int i = 0;i<7;i++){
            int x, y;
            scanf("%d.%d", &x, &y);
            pts[i].P[0] = x*1000+y;
            scanf("%d.%d", &x, &y);
            pts[i].P[1] = x*1000+y;
        }
        double p;
        in_F(p);
        int ans = 0;
        double diff = 1e9;
        for(int i = 0;i<perm_cnt;i++){
            if(invalid(i))
                continue;
            long long area = 0;
            for(int j = 1;j<7-1;j++){
                long long x1 = pts[perms[i][j]-1].P[0] - pts[perms[i][0]-1].P[0];
                long long y1 = pts[perms[i][j]-1].P[1] - pts[perms[i][0]-1].P[1];
                long long x2 = pts[perms[i][j+1]-1].P[0] - pts[perms[i][0]-1].P[0];
                long long y2 = pts[perms[i][j+1]-1].P[1] - pts[perms[i][0]-1].P[1];
                area += x1*y2 - x2*y1;
            }
            double area_x = abs(area)/2.0;
            double new_p = area_x/4000000.0;
            new_p = new_p*new_p*new_p;
            double new_diff = abs(new_p - p);
            if(new_diff < diff){
                diff = new_diff;
                ans = i;
            }
            if(diff <= 1e-6)
                break;
        }
        for(int i = 0;i<7;i++){
            printf("%d ", perms[ans][i]);
        }
        newline;
    }
}
