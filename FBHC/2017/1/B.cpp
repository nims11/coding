#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
inline bool inside_square(pair<int, int> &pt, pair<int, int> &sqr, int R){
return pt.first >= sqr.first \
    && pt.first - sqr.first <= R\
    && pt.second >= sqr.second\
    && pt.second - sqr.second <= R;
}
int main(){
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int N, R;
        in_I(N);
        in_I(R);
        vector<pair<int, int>> points;
        for(int i = 0;i<N;i++){
            int x, y;
            in_I(x);
            in_I(y);
            points.push_back({x, y});
        }
        sort(points.begin(), points.end());
        vector<pair<int, int>> squares;
        for(int i = 0;i<N;i++){
            for(int j = i;j<N;j++){
                if(points[j].first - points[i].first <= R && abs(points[j].second - points[i].second) <= R)
                    squares.push_back({points[i].first, min(points[i].second, points[j].second)});
            }
        }
        int ans = 0;
        for(int i = 0;i<squares.size();i++){
            for(int j = i;j<squares.size();j++){
                int res = 0;
                for(int k = 0;k<N;k++){
                    if(inside_square(points[k], squares[i], R) || inside_square(points[k], squares[j], R))
                        res++;
                }
                ans = max(ans, res);
            }
        }
        cout<<ans<<endl;
    }
}
