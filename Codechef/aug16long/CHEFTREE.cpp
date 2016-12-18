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
int GCD(int a,int b){
    while(b){
        swap(a, b);
        b %= a;
    }
    return a;
}
inline int getQuad(int x, int y){
    if(x > 0 && y >= 0)
        return 0;
    else if(x <= 0 && y > 0)
        return 1;
    else if(x < 0 && y <= 0)
        return 2;
    else if(x >= 0 && y < 0)
        return 3;
}
inline pair<int, int> getRad(int x, int y, int quad){
    x = abs(x);
    y = abs(y);
    int gcd = GCD(x, y);
    x /= gcd;
    y /= gcd;
    if(quad%2) swap(x, y);
    return {y, x};
}

inline long long nC2(int n){
    return n*1LL*(n-1)/2;
}

inline long long nC3(int n){
    return n*1LL*(n-1)*(n-2)/6;
}

struct Point{
    pair<int, int> pos;
    pair<int, int> rad;
    double getAngle() const{
        return rad.first/double(rad.second);
    }

    friend bool operator<(const Point &a, const Point &b);
};

bool operator<(const Point &a, const Point &b){
    if(a.rad != b.rad)
        return a.getAngle() < b.getAngle();
    return a.pos < b.pos;
}

int N;
set<Point> pts[4];
int main(){
    in_I(N);
    for(int i = 0;i<N;i++){
        Point p;
        in_I(p.pos.first);
        in_I(p.pos.second);
        int quad = getQuad(p.pos.first, p.pos.second);
        p.rad = getRad(p.pos.first, p.pos.second, quad);
        pts[quad].insert(p);
        long long badTriangles = 0;
        for(int q = 0; q < 4; q++){
            int endQ = (q+2)%4;
            auto it2 = pts[endQ].begin();
            int cnt2 = 0, cnt1 = pts[q].size();
            for(auto it1 = pts[q].begin(); it1 != pts[q].end(); it1++){
                cnt1--;
                while(it2 != pts[endQ].end() && it2->getAngle() <= it1->getAngle())
                    it2++, cnt2++;
                badTriangles += nC2(cnt1+cnt2);
            }
        }
        cout<<badTriangles<<endl;
    }
}
