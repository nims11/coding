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
POINT<int> pts[51];
int ccw(POINT<int> a, POINT<int> b, POINT<int> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
int res[51];
int dp[51][51][51]; // i, j, k -> i to j clockwise, i or j is either left-bot most or right-top most.
int N;
int b[51];
#define INF 1000000000
int getans(int st, int x, int y, int z){
    int ii;
    // cin>>ii;
    //
    // cout<<st<<" "<<x<<" "<<y<<" "<<dp[x][y][z]<<endl;
    if(z < 1 || (z>1 && y == st))
        return INF;
    if(dp[x][y][z] != INF){
        return dp[x][y][z];
    }

    int &ans = dp[x][y][z];
    ans = INF+1;
    int tmp = 0;
    for(int i = 0;i<N;i++){
        if(ccw(pts[st], pts[i], pts[y]) == ccw(pts[y], pts[i], pts[x]) &&
                ccw(pts[x], pts[i], pts[st]) == ccw(pts[y], pts[i], pts[x]))
            tmp += b[i];
        if((pts[st] < pts[i] || st == i) && ccw(pts[x], pts[y], pts[i]) < 0 && (ccw(pts[st], pts[y], pts[i]) < 0 || st == i)){
            int res = getans(st, y, i, z-1);
            if(res < INF)
                ans = min(ans, res+b[y]);
        }
    }
    ans += (st != x && st != y?tmp:0);
    ans = min(INF+1, ans);
    return ans;
}
int main()
{
    scanf("%d", &N);
    int x, y;
    for(int i = 0;i<N;i++){
        scanf("%d%d%d", &x, &y, &b[i]);
        pts[i].P[0] = x;
        pts[i].P[1] = y;
    }
    for(int i = 0;i<=N;i++)
        res[i] = INF;
    for(int z = 0;z<N;z++){
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                for(int k = 0;k<=N;k++)
                    dp[i][j][k] = INF;
        for(int i = 0;i<N;i++)
            if(pts[z]<pts[i])
                dp[i][z][1] = b[z];
        for(int i = 0;i<N;i++){
            // cout<<i<<endl;
            if(i != z && pts[z] < pts[i]){
                for(int k = 3;k<=N;k++){
                    res[k] = min(res[k], getans(z, z, i, k));
                    // if(k == 3 && getans(z, z, i, k) == 5){
                    //     cout<<z<<" "<<i<<endl;
                    //     return 0;
                    // }
                }
            }
        }
    }
    for(int k = 3;k<=N;k++){
        if(res[k] == INF)
            cout<<-1<<" ";
        else
            cout<<res[k]<<" ";
    }
    cout<<endl;
}
