/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
using namespace std;
vector<int> primes;
int Primes[2000];int Count=0;
bool isPrime(long n)
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
void generatePrimes(long n)
{
  primes.push_back(2);
  for(long i=3;i<=n;i+=2)
  {
    if(isPrime(i))
    {primes.push_back(i);if(i>1000)Primes[Count++]=i;}
  }
}
struct _PRIME
{
    int a[4];
}tmp;
int search_b(int n)
{
    int start=0,end=Count-1;
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(Primes[mid]<n)
        {
            start=mid+1;
            continue;
        }
        if(Primes[mid]>=n)
        {
            end=mid;
            continue;
        }
    }
    return end;
}
vector<_PRIME> nodes;
queue<int> BFS;
void clear( std::queue<int> &q )
{
   std::queue<int> empty;
   std::swap( q, empty );
}
int visited[2000];
int main()
{
    generatePrimes(9999);
    for(int i=0;i<Count;i++)
    {
        tmp.a[0]=Primes[i]%10;
        tmp.a[1]=(Primes[i]/10)%10;
        tmp.a[2]=(Primes[i]/100)%10;
        tmp.a[3]=(Primes[i]/1000)%10;
        nodes.push_back(tmp);
    }
    int a,b;
    in_T
    {
        in_I(a);in_I(b);
        int src,dest;
        src=search_b(a);
        dest=search_b(b);
        if(a==b){printf("0\n");continue;}
        for(int i=0;i<Count;i++)
        visited[i]=-1;

        visited[src]=0;
        BFS.push(src);
        int k,l;
        int ans;
        while(!BFS.empty())
        {
            k=BFS.front();BFS.pop();
            for(int i=0;i<Count;i++)
            {
                if(visited[i]==-1)
                {
                    l=0;
                    for(int j=0;j<4;j++)
                    if(nodes[i].a[j]==nodes[k].a[j])
                    l++;
                    if(l==3)
                    {
                        visited[i]=1+visited[k];
                        if(i==dest)
                        {
                            ans=visited[i];
                            clear(BFS);
                            break;
                        }
                        BFS.push(i);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
