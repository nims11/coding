#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;

using namespace std;

int arr[2][100010];
int main(){
    int z = 0;
    in_T{
        z++;
        int N;
        in_I(N);
        for(int i = 0; i < N; i++){
            in_I(arr[i%2][i/2]);
        }
        sort(arr[0], arr[0] + (N+1)/2);
        sort(arr[1], arr[1] + (N)/2);
        int idx = -1;
        for(int i = 1; i < N && idx == -1; i++){
            if(arr[i%2][i/2] < arr[(i-1)%2][(i-1)/2]){
                idx = i;
            }
        }
        printf("Case #%d: ", z);
        if(idx == -1)
            printf("OK\n");
        else
            printf("%d\n", idx-1);
    }
}
