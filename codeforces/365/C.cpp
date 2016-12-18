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
int ccw(POINT<int> a, POINT<int> b, POINT<int> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
POINT<int> polygon[10010];

int getTan(int l, int r){
    int diffy = polygon[r].P[1] - polygon[l].P[1];
    int diffx = polygon[r].P[0] - polygon[l].P[0];
    if(diffx == 0)
        return 1e8;
    return double(diffy) / diffx;
}
int main(){
    int n, w, v, u;
    in_I(n);in_I(w);in_I(v);in_I(u);
    int leftest = 0;
    int bottomest = 0;
    int rightest = 0;
    for(int i = 0;i<n;i++){
        int x, y;
        in_I(x);in_I(y);
        polygon[i].P[0] = x;
        polygon[i].P[1] = y;
        if(polygon[leftest].P[0] > polygon[i].P[0])
            leftest = i;
        if(polygon[i].P[1] < polygon[bottomest].P[1])
            bottomest = i;
        if(polygon[rightest].P[0] < polygon[i].P[0])
            rightest = i;
    }
    vector<int> leftestvec;
    bool wait = false;
    for(int i = 0;i<n;i++){
        if(polygon[leftest].P[0] == polygon[i].P[0])
            leftestvec.push_back(i);
        long long y = polygon[i].P[1];
        long long x = polygon[i].P[0];
        long long dist = x;
        if(dist * u < v * y){
            wait = true;
            break;
        }
    }

    if(!wait){
        printf("%.10lf\n", double(w)/u);
        return 0;
    }

    int curY = 0;
    int curVertex = bottomest;
    double curTime = 0;
    for(int i = bottomest; i != (rightest+1)%n; i = (i+1)%n){
        int dy = polygon[i].P[1] - curY;
        curY += dy;
        curTime += dy / double(u);
        double curXVertex = v*curTime;
        double diff = polygon[i].P[0] - curXVertex;
        // cout<<polygon[i].P[0]<<" "<<polygon[i].P[1]<<endl;
        // cout<<"curY = " <<curY<<endl;
        // cout<<"curTime = " <<curTime<<endl;
        // cout<<"diff = " <<diff<<endl;
        if(diff > 0){
            curTime += diff / v;
        }
    }
    curTime += (w-curY) / double(u);
    printf("%.10lf\n", curTime);
}
