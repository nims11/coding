/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
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
int res[10000001][10];
#define MAX_N 10000000
int sieve[MAX_N+1];
vector<int> primes;
vector<int> foo[10];
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
int s2[MAX_N+1];
int main()
{
    genPrimes();
    for(int i = 0;i<primes.size();i++){
        for(int j = primes[i];j<=MAX_N;j+=primes[i])
            s2[j]++;
    }
    int maxi = 0;
    for(int i = 2;i<=MAX_N;i++){
        foo[s2[i]].push_back(i);
    }
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int A, B, K;
        cin>>A>>B>>K;
        if(K>10)
            cout<<0<<endl;
        else
            cout<<int(upper_bound(BE(foo[K]), B)-lower_bound(BE(foo[K]), A))<<endl;
    }
}
