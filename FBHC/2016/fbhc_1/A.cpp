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
int dp[100010];
const int inf = mod+1;
bool valid(int st, int end){
    int correc = 0;
    for(int i = st+1;i<=end;i++){
        if(arr[i] <= arr[i-1])
            return false;
        for(int j = arr[i-1]+10;j<arr[i];j+=10){
            correc += 1;
        }
    }
    return (end-st+1 + correc <= 4);
}
int main(){
    int z = 0;
    in_T{
        int N;
        in_I(N);
        for(int i = 0;i<N;i++)
            in_I(arr[i+1]);
        for(int i = 0;i<=N;i++)
            dp[i] = inf;
        dp[0] = 0;
        for(int i = 1;i<=N;i++){
            for(int j = i-1;j>=i-4 && j>=0;j--){
                if(dp[j] == inf)
                    continue;
                if(valid(j+1, i)){
                    dp[i] = min(dp[i], 4-(i-j) + dp[j]);
                }
            }
        }
        cout<<"Case #"<<(++z)<<": "<<dp[N]<<endl;
    }
}
