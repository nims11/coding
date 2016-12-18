const long long M = 1000000007;
int fact[30001];
int inv[30001];
int degree(long long cur)
{
//    if(cur==0)return 1;
  int res = 1;
  int k = M-2;
  while (k)
  {
    if (k%2)
    {
      res = (res * cur)%M;
    }
    k /= 2;
    cur = (cur * cur) % M;
  }
  return res;
}

long long combinations(int n, int k) {
//    if(k==0)return 1;
  long long res = fact[n];
//  cout<<n<< " "<<k<<endl;
  res = (res*((inv[n-k]*(long long)inv[k])%M))%M;
  return res;
}
long long arr[10002];
int main()
{
    fact[1] = 1;
    fact[0] = 1;
    for(long long i=2;i<=30000;i++)
        fact[i] = (fact[i-1]*i)%M;
    for(int i=0;i<=30000;i++)
        inv[i] = degree(fact[i]);
}
