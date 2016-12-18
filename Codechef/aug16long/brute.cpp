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
int N, L;
struct Point{
    int x, y, c;
}points[100010];

long long getBeauty(int sideLength){
    long long S = 0;
    for(int i = 1;i<=10;i++){
        for(int j = 1;j<=10;j++){
            long long s = 0;
            for(int k = 1;k<=N;k++){
                int x = points[k].x;
                int y = points[k].y;
                if(i <= x && x < i+sideLength && j <= y && y < j+sideLength)
                    s += points[k].c;
            }
            S = max(S, s);
        }
    }
    return S;
}
int main(){
    in_I(N);in_I(L);
    for(int i = 1;i<=N;i++){
        in_I(points[i].x);
        in_I(points[i].y);
        in_I(points[i].c);
    }
    sort(points+1, points+N+1, [](const Point &p1, const Point &p2) -> bool {return p1.x < p2.x;});
    long long S = getBeauty(L);
    int st = 1, end = L;
    while(st < end){
        int mid = (st + end)/2;
        if(getBeauty(mid) == S){
            end = mid;
        }else
            st = mid+1;
    }
    printf("%lld %d\n", S, end);
}
