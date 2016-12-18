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
int sieve[1000001];
int res[1000001];
vector<int> primes;
int main()
{
    for(int i = 2; i<= 1000000; i++)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            if(i*1LL*i<=1000000)
            for(int j = i*i; j<= 1000000; j+=i)
                sieve[j] = 1;
        }
    }
    for(int i = 0; i< primes.size(); i++)
    {
//        cout<<primes[i]<<endl;
        for(long long j = primes[i]; j<=1000000; j *= primes[i])
        {
            if((j*primes[i]-1)%(primes[i]-1) == 0)
            {
                long long x = (j*primes[i]-1)/(primes[i]-1);

                if(sieve[x] == 0 && x<1000000)
                {
                    res[j] = 1;
                }
            }
        }
//        cin>>primes[i];
    }
    for(int i = 1; i<=1000000;i ++)
    {
        res[i] += res[i-1];
    }
    int A, B;
    in_T
    {
        in_I(A);in_I(B);
        printf("%d\n", res[B]-res[A-1]);
    }
}
