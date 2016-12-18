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

const int MAXN = 100002;
struct LogCache {
    int LOG2[MAXN];
    LogCache();
};
LogCache::LogCache(){
    int curr = 2;
    LOG2[1] = 0;
    for(int i = 2; i<=100001;i++){
        if(i == curr){
            curr <<= 1;
            LOG2[i] = LOG2[i-1] + 1;
        }else
            LOG2[i] = LOG2[i-1];
    }
}

struct RMQ{
    int n;
    int aux[MAXN][22];
    static LogCache logCache;
    void init(int n, const int *arr);
    int query(int x, int y);
}rmq;
LogCache RMQ::logCache;
void RMQ::init(int n, const int *arr){
    this->n = n;
    for(int i=1;i<=n;i++){
        aux[i][0] = arr[i];
    }
    for(int j=1; (1<<j)<=n+1; j++)
        for(int i=1;i+(1<<j)<=n+1;i++)
            aux[i][j] = max(aux[i][j-1], aux[i+(1<<(j-1))][j-1]);
}
int RMQ::query(int x, int y){
    int k = logCache.LOG2[y-x+1];
    return max(aux[x][k], aux[y-(1<<k)+1][k]);
}

int arr[MAXN];
int main(){
    int n;
    in_I(n);
    for(int i = 1;i<=n;i++){
        in_I(arr[i]);
    }

    rmq.init(n, arr);
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if((arr[i]&arr[j]) == arr[i] || (arr[i]&arr[j]) == arr[j]){
                ans += rmq.query(i, j);
            }
        }
    }
    printf("%lld\n", ans);
}
