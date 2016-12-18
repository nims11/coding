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

int N;
int arr[14];
int dp[1<<14];
#define MAX_N 15000
int sieve[MAX_N+1];
void genPrimes(){
	for(int i = 2;i<=MAX_N;i++){
		if(sieve[i] == 0){
			for(int j = i;j<=MAX_N;j+=i)
				sieve[j]++;
		}
	}
}
int getans(int mask){
    int tmp[N];
    if(dp[mask] != -1)
        return dp[mask];
    int tmpcnt = 0;
    for(int i = 0;i<N;i++){
        if(mask&(1<<i)){
            tmp[tmpcnt++] = i;
        }
    }
    int &ans = dp[mask];
    for(int mask2 = 1;mask2<(1<<tmpcnt);mask2++){
        int mask3 = mask;
        int sum = 0;
        for(int i = 0;i<tmpcnt;i++){
            if(mask2 & (1<<i)){
                mask3 ^= (1<<tmp[i]);
                sum += arr[tmp[i]];
            }
        }
        // cout<<sum<<" "<<sieve[sum]<<endl;
        ans = max(ans, sieve[sum]+getans(mask3));
    }
    return ans;
}
int main(){
    genPrimes();
    for(int i = 0;i<(1<<14);i++)
        dp[i] = -1;
    dp[0] = 0;
    in_I(N);
    for(int i = 0;i<N;i++)
        in_I(arr[i]);
    cout<<getans((1<<N)-1)<<endl;
}
