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
#define BE(a) a.begin(), a.end()

using namespace std;

#define MAX_N 1000000
int sieve[MAX_N+1];
vector<long long> primes;
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
int main()
{
    genPrimes();
    vector<long long> pre = primes;
    for(int i = 1;i<primes.size();i++)
        pre[i] += pre[i-1];
    for(int i = 543;i>0;i--){
        for(int j = i-1;j<primes.size();j++){
            long long req = pre[j]-(j-i>=0?pre[j-i]:0);
            if(binary_search(BE(primes), req)){
                cout<<req<<endl;
                return 0;
            }
        }
    }
}
