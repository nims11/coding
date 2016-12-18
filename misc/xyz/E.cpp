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
int main(){
    
}
