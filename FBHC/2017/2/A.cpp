#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

const int INF = 1e9;
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
int ccw(POINT<int> a, POINT<int> b, POINT<int> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
int k;
int getans(int n, int m){
    int res = 1;
    int cur_col = k+2;
    int col = 0;
    if(k + k + 1 > n)
        return INF;
    int diff = cur_col - col;
    int fac = diff / k + (diff %k != 0);
    col += k*fac;
    res += fac;
    res++;
    col += k+1;
    if(col >= m)
        return INF;
    return res;
}
int getans2(int n, int m){
    if(1 + k + 1 + k + 1 > m || k + 1 > n)
        return INF;
    return (n / k) + (n%k != 0);
}
int main(){
   int z = 0;
   in_T{
       z++;
       cout<<"Case #"<<z<<": ";
       int n, m;
       cin>>n>>m>>k;
       int res = min(getans(n, m), getans(m, n));
       res = min(res, min(getans2(n, m), getans2(m, n)));
       if(res == INF)
           cout<<-1<<endl;
       else
           cout<<res<<endl;
   }
}
