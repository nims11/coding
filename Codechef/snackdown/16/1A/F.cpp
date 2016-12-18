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
int arr[100010];
int N,m;
long long x, y;
long long getans(long long lval, long long rval, int m, long long lidx, long long ridx){
    // cout<<x<<" "<<y<<" "<<" "<<lidx<<" "<<ridx<<endl;
    if(m == 0){
        long long ans = 0;
        if(x <= lidx && lidx <= y)
            ans = ADD(ans, lval);
        if(x <= ridx && ridx <= y)
            ans = ADD(ans, rval);
        return ans;
    }
    if(x <= lidx && y >= ridx){
        long long curKid = 1;
        long long curSum = 1;
        for(int i = 0 ;i<m;i++){
            curKid = curKid*(i==0?1:3);
            curKid %= mod;
            curSum += curKid;
            curSum %= mod;
        }
        return ADD(MUL(curSum, lval),MUL(curSum, rval));
    }
    long long mid = (lidx+ridx+1)/2;
    if(x >= mid){
        return getans(ADD(lval, rval), rval, m-1, mid, ridx);
    }else if(y <= mid){
        return getans(lval, ADD(lval, rval), m-1, lidx, mid);
    }else{
        long long lres = getans(ADD(lval, rval), rval, m-1, mid, ridx);
        long long rres = getans(lval, ADD(lval, rval), m-1, lidx, mid);
        lres = ADD(lres, rres);
        lres -= ADD(lval, rval);
        lres %= mod;
        if(lres < 0)
            lres += mod;
        return lres;
    }
}
int main(){
    in_T{ 
        in_I(N);
        in_I(m);in_L(x);
        in_L(y);
        for(int i = 1;i<=N;i++)
            in_I(arr[i]);
        long long segment_size = 2;
        for(int i = 1;i<=m;i++)
            segment_size += (segment_size-1);
        long long ans = 0;
        for(int i = 1;i<=N-1;i++){
            long long l = (i-1)*(segment_size-1)+1;
            long long r = (i)*(segment_size-1)+1;
            if((x < r || (x == r && i == N-1)) && y >= l){
                ans = ADD(ans, getans(arr[i], arr[i+1], m, l, r));
            }

            if((x < l && y >= l)){
                ans -= arr[i];
                ans %= mod;
                if(ans < 0)
                    ans += mod;
            }
        }
        if(N == 1)
            printf("%d\n", arr[1]);
        else
            printf("%lld\n", ans);
    }
}
