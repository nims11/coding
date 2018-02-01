#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

long long C[255], D[255];
long long N, M, e;
int getans(long long diff){
    int ret = 0;
    int i = 0, j = 0;
    while(i < N && j < M){
        if(abs(C[i] + diff - D[j]) <= e){
            i++;
            j++;
            ret++;
        }else if(C[i] + diff - D[j] > e){
            j++;
        }else
            i++;
    }
    return ret;
}
int main(){
    in_T{
        in_L(N);
        in_L(M);
        in_L(e);
        for(int i = 0;i<N;i++)
            in_L(C[i]);
        for(int i = 0;i<M;i++)
            in_L(D[i]);
        sort(C, C+N);
        sort(D, D+M);
        int ans = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                ans = max(ans, getans(D[j] - e - C[i]));
            }
        }
        printf("%d\n", ans);
    }
}
