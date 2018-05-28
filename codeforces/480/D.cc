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
template <typename T>
inline T MUL(T a, T b) { return (a*1LL*b)%mod; }
template <typename T>
inline T ADD(T a, T b) { return (a+0LL+b)%mod; }

using namespace std;

int arr[5001];
int dp[2][5001];
unordered_map<int, int> last_odd;
#define MAX_N 10000
int sieve[MAX_N+1];
vector<int> primes;
void genPrimes(){
    primes.push_back(2);
    for(int i = 3;i<=MAX_N;i+=2){
    if(sieve[i] == 0){
        primes.push_back(i);
        if(i*1LL*i <= MAX_N)
        for(int j = i*i;j<=MAX_N;j+=i)
            sieve[j] = 1;
    }
    }
}
int get_odd_part(int n){
    if(!n) return n;
    int ret = 1;
    for(int p: primes){
        int flag = 0;
        while(n % p == 0){
            flag ^=1;
            n /= p;
        }
        if(flag)
            ret *= p;
        if(p > abs(n)) break;
    }
    ret *= n;
    return ret;
}
int result[5001];
int main(){
    genPrimes();
    int n;
    in_I(n);
    for(int i = 0; i < n; i++){
        in_I(arr[i]);
        arr[i] = get_odd_part(arr[i]);
    }
    dp[0][0] = 1;
    result[1]++;
    int last_even_pos = -1, last_even_neg = -1, last_zero = -1;
    if(arr[0] == 1)
        last_even_pos = 0;
    else if(arr[0] == -1)
        last_even_neg = 0;
    else if(arr[0] == 0)
        last_zero = 0;
    else
        last_odd[arr[0]] = 0;

    for(int i = 1; i < n; i++){
        int ii = i%2;
        dp[ii][i] = 1;
        int lt;
        if(abs(arr[i]) <= 1){
            if(arr[i] > 0){
                lt = last_even_pos;
                last_even_pos = i;
            }else if(arr[i] < 0){
                lt = last_even_neg;
                last_even_neg = i;
            }else {
                last_zero = i;
            }
        } else {
            if(last_odd.find(arr[i]) == last_odd.end()){
                lt = -1;
            }else
                lt = last_odd[arr[i]];
            last_odd[arr[i]] = i;
        }
        if(arr[i] == 0){
            for(int j = i-1; j>=0; j--)
                dp[ii][j] = dp[!ii][j];
        }else {
            long long sum = 0;
            for(int j = i-1; j>lt; j--){
                sum += abs(arr[j]);
                if(sum == 0){
                    dp[ii][j] = 1;
                }else
                    dp[ii][j] = dp[!ii][j] + 1;
            }
            for(int j = lt; j >= 0; j--){
                dp[ii][j] = dp[!ii][j];
            }
        }

        for(int j = 0; j <= i; j++){
            /* cout<<dp[ii][j]<<" "; */
            result[dp[ii][j]]++;
        }
        /* cout<<endl; */
    }

    for(int i = 1; i <= n; i++){
        printf("%d ", result[i]);
    }
    newline;
}
