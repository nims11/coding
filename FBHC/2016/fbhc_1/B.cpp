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
int W[100010];
int L, N, M, D;
long long getMaxOutWashTime(){
    long long st = 0, end = L*1LL*W[0];
    while(st < end){
        long long mid = (st + end)/2;
        
        // max possible loadouts within t = mid
        long long max_poss = 0;
        for(int i = 0;i<N;i++){
            max_poss += mid/W[i];
        }
        
        if(max_poss < L)
            st = mid + 1;
        else
            end = mid;
    }
    return end;
}
long long tmp[1000010];
int main(){
    int z = 0;
    in_T{
        queue<long long> bfs;
        long long ans = 0;
        scanf("%d%d%d%d", &L, &N, &M, &D);
        for(int i = 0;i<N;i++){
            in_I(W[i]);
        }
        long long max_wash_out_time = getMaxOutWashTime();
        int cnt = 0;
        for(int i = 0;i<N;i++){
            for(long long j = W[i]; j<max_wash_out_time; j+=W[i]){
                tmp[cnt++] = j;
            }
        }

        sort(tmp, tmp+cnt);
        while(cnt < L)
            tmp[cnt++] = max_wash_out_time;
        int cur = 0;
        for(int i = 0;i<min(L, M);i++)
            bfs.push(0);
        while(cur < L){
            long long nextDryer = bfs.front();
            bfs.pop();
            ans = max(tmp[cur], nextDryer) + D;
            bfs.push(ans);
            cur++;
        }
        cout<<"Case #"<<(++z)<<": "<<ans<<endl;
    }
}
