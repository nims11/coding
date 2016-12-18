/*
ID: nimeshg1
PROG: sprime
LANG: C++
*/
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
#include<fstream>
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
ifstream fin("sprime.in");
ofstream fout("sprime.out");
#define cin fin
#define cout fout

const int max_p = sqrt(100000000);
const int lt2 = max_p/2+1;

vector<int> primes;
vector<bool> sieve(lt2);

void generatePrimes()
{
    primes.push_back(2);
    int lt1 = sqrt(max_p);
    for(int i=3;i<=lt1;i+=2)
    {
        if(!sieve[i>>1])
        {
            for(int j=i*i;j<=max_p;j+=i)
            {
                if(j&1)
                    sieve[j>>1] = 1;
            }
        }
    }
    for(int i=1;i<lt2;i++)
    {
        if(!sieve[i])
            primes.push_back((i<<1)+1);
    }
}
bool isPrime(int n)
{
    if(n==1)
    return 0;
  int len=primes.size();
  int limit=sqrt(n);
  for(int i=0;i<len && primes[i]<=limit;i++)
    if(n%primes[i]==0)
      return false;
    return true;
}
int n;
void dfs(int len, int pre)
{
    if(len == n)
    {
        cout<<pre<<endl;
        return;
    }
    for(int i=(pre==0);i<10;i++)
    {
        int x = pre*10+i;
        if(isPrime(x))
            dfs(len+1, x);
    }
}
int main()
{
    cin>>n;
    generatePrimes();
    dfs(0,0);
}
