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
set<int> primeset;
vector<int> primes;
int sieve[1001];
int pos[200];
bool isPrime(int N){
    int i = 0;
    for(int i = 0;i<primes.size() && primes[i]<N;i++){
        if(N%primes[i] == 0)
            return false;
    }
    return true;
}

bool getans(int N){
    int N2 = N;
    if(N == 1)
        return false;
    if(isPrime(N)){
        if(N == 2){
            return true;
        }else{
            return !getans(N-1);
        }
    }else{
        bool res = false;
        for(int i = 0;i<primes.size() && primes[i]<N;i++){
            if(N2%primes[i] == 0){
                res |= !pos[i];
                while(N2%primes[i] == 0)
                    N2/=primes[i];
            }
        }
        if(!res)
        return !res;
        return !(getans(N2)|getans(N-1));
    }
}
int main()
{
    primes.push_back(2);
    primeset.insert(2);
    for(int i = 3;i<=1000;i+=2){
        if(sieve[i] == 0){
            primes.push_back(i);
            primeset.insert(i);
            for(int j = i*i;j<=1000;j+=i)
                sieve[j] = 1;
        }
    }
    for(int i = 0;i<primes.size();i++)
    {
        pos[i] = getans(primes[i]);
        cout<<primes[i]<<" "<<pos[i]<<endl;
    }
//    for(int i = 2;i<=100;i++)
//        cout<<i<<" "<<getans(99999989)<<endl;
    in_T{
        int N;
        in_I(N);
        printf(getans(N)?"Mike\n":"Tom\n");
    }
}
