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
#define MAX_N 100
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
set<pair<int, int> > foo;
pair<int, int> getpow(int x){
    pair<int, int> ret;
    for(int a = 2;a<=x;a++){
        ret.first = a;
        ret.second = 0;
        int y = x;
        while(y % a == 0)
            y/=a, ret.second++;
        if (y == 1)
            return ret;
    }
}
int main()
{
    genPrimes();
    for(int a = 2;a<=100;a++)
        for(int b = 2;b<=100;b++){
            pair<int, int> x = getpow(a);
            foo.insert(make_pair(x.first, x.second * b));
        }
    cout<<foo.size()<<endl;
}
