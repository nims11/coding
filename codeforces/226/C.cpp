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
int sieve[3162];
vector<int> primes;
void generatePrimes()
{
    for(int i=2;i<3162;i++)
    {
        if(sieve[i] == 0){
            for(int j = i*i;j<3162;j+=i)
                sieve[j] = 1;
        }
    }
    for(int i = 2;i<3162;i++)
        if(!sieve[i])
            primes.push_back(i);
}
long long presum[500];
vector<int> second;
int main()
{
    generatePrimes();
    int n,x;
    in_I(n);
    for(int i = 0;i<n;i++)
    {
        int x;
        in_I(x);
        for(int j = 0;j<primes.size() && primes[j] <= x;j++){
            if(x%primes[j] == 0){
                presum[j]++;
                while(x%primes[j] == 0)x/=primes[j];
            }
        }
        if(x != 1)
                second.push_back(x);
    }
    sort(second.begin(), second.end());
    for(int i = 1;i<500;i++)
        presum[i] += presum[i-1];
    int m, l,r;
    in_I(m);
    while(m--){
        in_I(l);in_I(r);
        long long res = 0;
        int q1 = lower_bound(primes.begin(), primes.end(), l)-primes.begin();
        int q2 = upper_bound(primes.begin(), primes.end(), r)-primes.begin();
        q2--;
        if(q1 <= q2 && q2 >= 0)
            res += presum[q2]-(q1==0?0:presum[q1-1]);

        q1 = lower_bound(second.begin(), second.end(), l)-second.begin();
        q2 = upper_bound(second.begin(), second.end(), r)-second.begin();
        q2--;

        if(q1 <= q2 && q2 >= 0)
            res += q2-q1+1;

    cout<<res<<endl;
    }
}
