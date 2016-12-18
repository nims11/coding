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
int arr[1001];
set<int> prime_factors[1001];
int form[1001];
#define MAX_N 1001
int sieve[MAX_N+1];
vector<int> primes;
set<int> foo;
void genPrimes(){
    primes.push_back(2);
    prime_factors[2].insert(2);
    for(int i = 3;i<=MAX_N;i+=2){
        if(prime_factors[i].size() == 0){
            primes.push_back(i);
            for(int j = i;j<=MAX_N;j+=i)
                prime_factors[j].insert(i);
        }
    }
}
int dp[1001];
int getForm(int x){
    int ret = 1;
    for(int i: prime_factors[x])
        ret *= i;
    return ret;
}
int GCD(int a,int b){
    while(b){
        swap(a, b);
        b %= a;
    }
    return a;
}
int getans(){
    int ret = 0;
    for(int i = 0;i<N;i++){
        if(GCD(x, arr[i]) == 1){

        }
    }
}
int main(){
    genPrimes();
    for(int i = 1;i<=1000;i++)
        form[i] = getForm(i);
    in_T{
        in_I(N);
        for(int i = 0;i<N;i++)
            in_I(arr[i]);
        int res = 0;
        for(int i = 0;i<N;i++){
            foo.clear();
            for(int j: prime_factors[i])
                foo.insert(j);
            res = max(res, getans());
        }
        printf("%d\n", res);
    }
}
