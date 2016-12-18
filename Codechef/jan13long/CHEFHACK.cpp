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
vector<int>::iterator it;
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
  for(int i=3;i<=n;i+=2)
  {
    if(isPrime(i))
    {primes.push_back(i);}
  }
}
int ISPRIMES(int n)
{
    int tmp = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
    if(tmp<primes.size() && primes[tmp] == n)
        return tmp;
    return -2;
}
int foo[4] = {0,0,1,-1};
int bar[4] = {1,-1,0,0};
int main()
{
    generatePrimes(10000007);
    cout<<primes.size();
    in_T
    {
        int n;
        in_I(n);
        int grid[n][n][3];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                in_I(grid[i][j][0]);
        long long ans= 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j][2] = 0;
                if(grid[i][j][0]%2==0 && grid[i][j][0]!=2)
                {
                    grid[i][j][1] = -1;
                }else
                {
                    grid[i][j][1] = ISPRIMES(grid[i][j][0]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j][2])continue;
                if(grid[i][j][1]>=0)
                {
                    ans+=grid[i][j][1];
                    grid[i][j][2] = 1;
                }else
                {
                    if(grid[i][j][1]==-1)
                    {
                        ans += grid[i][j][0]/2;
                    }else
                    {
                        ans += (grid[i][j][0]+3)/2;
                    }
                    queue<pair<int, int> > BFS;
                    BFS.push(make_pair(i, j));
                    while(!BFS.empty())
                    {
                        pair<int, int> tmp = BFS.front();
                        BFS.pop();
                        if(grid[tmp.first][tmp.second][2])continue;
                        grid[tmp.first][tmp.second][2] = 1;
                        for(int k=0;k<4;k++)
                        {
                            int r = tmp.first + foo[k], c = tmp.second+bar[k];
                            if(r>=0 && c>=0 && r<n && c<n && grid[r][c][1]==grid[tmp.first][tmp.second][1])
                                BFS.push(make_pair(r,c));
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
