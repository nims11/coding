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
#define MAX_N 100010
int sieve[MAX_N+1];
vector<int> primes;
void genPrimes(){
    primes.push_back(2);
    for(int i = 3;i<=MAX_N;i+=2){
        if(sieve[i] == 0){
            primes.push_back(i);
            if(i*1LL*i <= MAX_N)
            for(int j = i*i;j<=MAX_N;j+=i)
                sieve[j]++;
        }
    }
}
int main(){
    int N;
    in_I(N);
    genPrimes();
    int xorsum = 0;
    for(int i = 0;i<N;i++){
        int x;
        in_I(x);
        int y = 0;
        for(int j = 0;j<(int)primes.size() && x > 1;j++){
            while(x % primes[j] == 0){
                y++;
                x /= primes[j];
            }
        }
        xorsum ^= y;
    }
    if(xorsum){
        printf("AMAN");
    }else
        printf("JASBIR");
}
