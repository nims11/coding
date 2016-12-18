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
int main()
{
    int z = 0;
    in_T{
        z++;
        int N;
        long long X, V;
        long long x1, x2, v1, v2;
        scanf("%d %lld.%lld %lld.%lld", &N, &v1, &v2, &x1, &x2);
        X = x1*10000 + x2;
        V = v1*10000 + v2;
        long long ri[N], xi[N];
        for(int i = 0;i<N;i++){
            scanf("%lld.%lld %lld.%lld", &x1, &x2, &v1, &v2);
            ri[i] = x1*10000 + x2;
            xi[i] = v1*10000 + v2;
        }
        printf("Case #%d: ", z);
        if(N == 1){
            if(X == xi[0]){
                printf("%.8lf\n", double(V)/ri[0]);
            }else
                printf("IMPOSSIBLE\n");
        }else if(N == 2){
            if(xi[0] == xi[1] && xi[0] == X){
                printf("%.8lf\n", double(V)/(ri[0]+ri[1]));
                continue;
            }
            double v0 = (V) * (X-xi[1])/double(xi[0]-xi[1]);
            double v1 = V - v0;
            if(v0 < 0 || v1 < 0 || xi[0] == xi[1]){
                printf("IMPOSSIBLE\n");
            }else
                printf("%.8lf\n", max(double(v0)/ri[0], double(v1)/ri[1]));
        }
    }
}
