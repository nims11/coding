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
int primes[1000001], n;
int main()
{
    for(int i = 2; i<=1000000; i++)
    {
        if(primes[i] == 0)
        {
            primes[i] = i;
            if(1LL*i*i <= 1000000)
            for(int j = i*i; j<=1000000; j+=i)
                if(primes[j] == 0)primes[j] = i;
        }
    }
    primes[1] = 1;
//    for(int i = 1; i<=20; i++)
//        cout<<i<<" "<<primes[i]<<endl;
    in_T
    {
        in_I(n);
        printf("%d\n", n/primes[n]);
    }
}
