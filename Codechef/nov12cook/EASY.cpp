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
vector<int> primes;
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
void generatePrimes(int n)
{
  primes.push_back(2);
  for(long i=3;i<=n;i+=2)
  {
    if(isPrime(i))
    {primes.push_back(i);}
  }
}
int n;
int arr[100000];
int main()
{
    generatePrimes(sqrt(100000));
    in_T
    {
        in_I(n);
        int tmp;
        vector<int> init;
        in_I(tmp);
        int lt = sqrt(tmp);
        int j = 0;
        while(primes[j]<=lt && j<primes.size())
        {
            if(tmp%primes[j]==0)
            {
                init.push_back(primes[j]);
                while(tmp%primes[j]==0)
                tmp/=primes[j];
            }
            j++;
        }
        if(tmp>1)
        init.push_back(tmp);

        int touse[init.size()], cnt = init.size();
        for(int i = 0;i<init.size();i++)
        touse[i] = 1;
        for(int i=1;i<n;i++)
        {
            in_I(tmp);
            if(cnt)
            {
                for(int j =0; j<init.size();j++)
                {
                    if(touse[j] && tmp%init[j])
                    {
                        cnt--;
                        touse[j] = 0;
                    }
                }
            }
        }
        int ans = -1;
        for(int i=0;i<init.size();i++)
        {
            if(touse[i])
            {
                ans = init[i];
                break;
            }
        }
        printf("%d\n", ans);
    }
}
