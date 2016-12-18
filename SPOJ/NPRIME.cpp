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
const int max_p = 86028121;
const int lt2 = max_p/2+1;
using namespace std;

int primes[5000010];
vector<bool> sieve(lt2);
int n, i, j;
void generatePrimes()
{
    primes[0] =2;
    int lt1 = sqrt(max_p);
    for(i=3;i<=lt1;i+=2)
    {
        if(!sieve[i>>1])
        {
            for(j=i*i;j<=max_p;j+=i)
            {
                if(j&1)
                    sieve[j>>1] = 1;
            }
        }
    }
    int f = 1;
    for(i=1;i<lt2;i++)
    {
        if(!sieve[i])
            primes[f++] = (i<<1)+1;
    }
}
int main()
{
    generatePrimes();
    cout<<primes[100000-1]<<endl;
    in_T
    {
        in_I(n);
        printf("%d\n", primes[n-1]);
    }
}
