/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;

#define MAX_N 1000000
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
bool iscirc(int p){
    vector<int> P;
    if(p<10)return 0;
    while(p){
        P.push_back(p%10);
        p/=10;
    }
    reverse(P.begin(), P.end());
    bool ret = true;
    for(int i = 0;i<P.size();i++){
        int pp = 0;
        for(int j = 0; j < P.size()-i;j++){
            pp = pp*10 + P[j%P.size()];
        }
        if(binary_search(primes.begin(), primes.end(), pp));
        else return false;
        pp = 0;
        for(int j = i; j < P.size();j++){
            pp = pp*10 + P[j%P.size()];
        }
        if(binary_search(primes.begin(), primes.end(), pp));
        else return false;

    }
    return true;
}
int main()
{
    genPrimes();
    int res = 0;
    for(int a:primes){
        if(iscirc(a))
            res += a;
    }
    cout<<res<<endl;
}
