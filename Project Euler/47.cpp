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

#define MAX_N 300000
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
int mask = 0;
int req = (1<<4)-1;
int main()
{
    genPrimes();
    int n = 1;
    while(1){
        int N = n;
        int cnt = 0;
        int lt = sqrt(N);
        for(int i = 0;i<primes.size() && primes[i]<=lt;i++)
            if(N%primes[i] == 0){
                cnt++;
                while(N%primes[i] == 0)
                    N/=primes[i];
            }
        if(N != 1)
            cnt++;

        if(cnt == 4){
            mask |= (1<<(n%4));
        }else
            mask &= ~(1<<(n%4));
        if(mask == req){
            cout<<n-3<<endl;
            break;
        }
        n++;
    }
}
