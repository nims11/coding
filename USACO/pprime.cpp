/*
ID: nimeshg1
PROG: pprime
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
bool ans[21];
bool visited[21][21][21];
ifstream fin("pprime.in");
ofstream fout("pprime.out");
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
int int_len(int x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        x/=10;
    };
    return ret;
}
string make_palin1(int x, int len, int mid=-1)
{
    string ret = "", rett;
    while(x)
    {
        ret.push_back(x%10 + '0');
        x/=10;
    }
    if(mid!=-1)
        ret.push_back(mid+'0');
    ret += ret.substr(0,len);
    reverse(ret.begin(), ret.begin() + len);
    return ret;
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
int a,b;
int pow_10[11];
int main()
{
    pow_10[0] = 0;
    pow_10[1] = 1;
    for(int i=2;i<11;i++)
        pow_10[i] = pow_10[i-1]*10;
    generatePrimes();
    cin>>a>>b;
    int lt = min(int_len(b), 8);

    for(int l=int_len(a);l<=lt;l++)
    {
        int len = l/2;
        if(l%2 == 0)
        {
            for(int i=pow_10[len];i<pow_10[len+1];i++)
            {
                string str = make_palin1(i, len, -1);
                int x = atoi(str.c_str());
                if(x>b)break;
                if(isPrime(x))
                    cout<<x<<endl;
            }
        }else
        {
            {
                for(int i=pow_10[len];i<pow_10[len+1];i++)
                {
                    for(int mid=0;mid<10;mid++){
                    string str = make_palin1(i, len, mid);
//                    cout<<" "<<str<<endl;
                    int x = atoi(str.c_str());
                    if(x>b)
                    {
                        break;
                    }
                    if(x>=a && isPrime(x))
                        cout<<x<<endl;
                    }
                }
            }
        }
    }
}
