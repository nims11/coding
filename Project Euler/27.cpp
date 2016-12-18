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
#define MAX_N 3000000
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
int getans(int a, int b){
    for(int n = 0;;n++){
        if(binary_search(primes.begin(), primes.end(), n*n+n*a+b));
        else
            return n;
    }
}
int main()
{
    genPrimes();
    int res = 0;
    int prevAns = 0;
    for(int a = -1000;a<=1000;a++){
        for(int b = -1000; b<=1000;b++){
            int ans = getans(a, b);
            if(ans > prevAns)
                res = a*b, prevAns = ans;
        }
    }
    cout<<prevAns<<endl;
    cout<<res<<endl;
}
