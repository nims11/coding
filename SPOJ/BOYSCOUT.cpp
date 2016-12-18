/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;

template <class T>
class POINT{
    public:
    T P[2];
    POINT(){}
    POINT(T x, T y){P[0] = x, P[1] = y;}
    //dot
    long long operator*(const POINT &a){
        return a.P[0]*1LL*this->P[0] + a.P[1]*1LL*this->P[1];
    }
    POINT operator-(const POINT &b){
        return POINT(this->P[0] - b.P[0], this->P[1] - b.P[1]);
    }
    //cross
    long long operator^(const POINT &b){
        return this->P[0]*1LL*b.P[1] - this->P[1]*1LL*b.P[0];
    }
    bool operator<(const POINT &b){
        if(this->P[0] != b.P[0])return this->P[0]<b.P[0];
        return this->P[1] < b.P[1];
    }
};
POINT<int> pts[100];
int ccw(POINT<int> a, POINT<int> b, POINT<int> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
int dp[100][100]; // i, j, k -> i to j clockwise, i or j is either left-bot most or right-top most.
int N;
int getans(int st, int x, int y){
    // cout<<st<<" "<<x<<" "<<y<<" "<<dp[x][y]<<endl;
    int ii;
    // cin>>ii;
    if(dp[x][y] != -1)
        return dp[x][y];
    int &ans = dp[x][y];
    ans = -100000;
    for(int i = 0;i<N;i++){
        if((pts[st] < pts[i] || st == i) && ccw(pts[x], pts[y], pts[i]) < 0 && (ccw(pts[st], pts[y], pts[i]) < 0 || st == i)){
            int res = getans(st, y, i);
            if(res > 0)
                ans = max(ans, res+(x != st));
        }
    }
    // ans = max(-1, ans);
    return ans;
}
int main()
{
    scanf("%d", &N);
    double x, y;
    for(int i = 0;i<N;i++){
        scanf("%lf%lf", &x, &y);
        pts[i].P[0] = x*100;
        pts[i].P[1] = y*100;
    }
    int res = 0;
    for(int z = 0;z<N;z++){
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                dp[i][j] = -1;
        for(int i = 0;i<N;i++)
            if(pts[z]<pts[i])
                dp[i][z] = 2;
        dp[z][z] = 1;
        for(int i = 0;i<N;i++)
                if(i != z && pts[z] < pts[i]){
                    res = max(res, getans(z, z, i));
                    // cout<<res<<endl;
                }
    }
    printf("%d\n", res);
}
