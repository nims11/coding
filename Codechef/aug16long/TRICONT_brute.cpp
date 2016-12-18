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

    friend bool operator<(const Point &a, const Point &b);
};

bool operator<(const Point &a, const Point &b){
    if(a.rad != b.rad)
        return a.rad.first*1LL*b.rad.second < b.rad.first*1LL*a.rad.second;
    return a.pos < b.pos;
}

int N;
set<Point> pts[4];
/* A utility function to calculate area of triangle formed by (x1, y1), 
 *    (x2, y2) and (x3, y3) */
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed 
 *    by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{   
    /* Calculate area of triangle ABC */
    float A = area (x1, y1, x2, y2, x3, y3);

    /* Calculate area of triangle PBC */  
    float A1 = area (x, y, x2, y2, x3, y3);

    /* Calculate area of triangle PAC */  
    float A2 = area (x1, y1, x, y, x3, y3);

    /* Calculate area of triangle PAB */   
    float A3 = area (x1, y1, x2, y2, x, y);
    if(abs(A) < 1e-6 || abs(A1) < 1e-6 || abs(A2) < 1e-6 || abs(A3) < 1e-6)
        return false;

    /* Check if sum of A1, A2 and A3 is same as A */
    return abs(A-A1 - A2 - A3) < 1e-6;
}
int main(){
    in_I(N);
    vector<pair<int, int>> PPP;
    for(int i = 0;i<N;i++){
        int x, y;
        in_I(x);
        in_I(y);
        PPP.push_back({x, y});
        int ans = 0;
        for(int j = 0;j<PPP.size();j++){
            for(int k = j+1;k<PPP.size();k++){
                for(int l = k+1;l<PPP.size();l++){
                    if(isInside(PPP[j].first, PPP[j].second, PPP[k].first, PPP[k].second, PPP[l].first, PPP[l].second, 0, 0))
                        ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
