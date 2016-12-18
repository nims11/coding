#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
#define MAX_N 100000
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
int main(){
    in_T{
        int n;
        in_I(n);
        int x = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        if(x % 2 == 0){
            printf("Bob\n");
        }else
            printf("Alice\n");
    }
}
