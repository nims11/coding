#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;
double field[10000];
int main(){
    int n, r;
    in_I(n);
    in_I(r);
    vector<int> x;
    vector<double> y;
    for(int i = 0; i < n; i++){
        int xx;
        in_I(xx);

        double finaly = 0;
        if(i == 0)
            finaly = r;
        else{
            for(int j = max(0, xx - 2*r); j <= xx + 2 * r; j++){
                if(field[j] > 0){
                    int xxx = abs(j - xx);
                    finaly = max(finaly, sqrt(4*r*r - xxx*xxx) + field[j]);
                }
            }
        }
        field[xx] = finaly;
        x.push_back(xx);
        y.push_back(finaly);
    }
    for(int i = 0; i < n; i++){
        printf("%.8f ", y[i]);
    }
}
