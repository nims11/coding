/*
    Nimesh Ghelani (nims11)
    Rabin Karp + Hashing
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
#include<cassert>
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
const int mod = 1000003;
int k;
char str[30010];
set<int> table[1000003];
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
bool check(int hash_val, int val)
{
    return (table[hash_val].find(val) != table[hash_val].end());
}
int main()
{
    in_I(k);
    in_S(str);
    int n = k;
    int init = 0;
    for(int i=0;i<k;i++)
        init = (26*init + str[i]-'a')%mod;
    table[init].insert(k-1);
    int h = POW(26, k-1);
    for(int i=k;str[i];i++,n++)
    {
        init = (26*(init-(str[i-k]-'a')*h) + str[i]-'a')%mod;
        if(init<0)init = (init+mod)%mod;
        table[init].insert(i);
    }
    init = 0;
    for(int i=n-1;i>n-1-k;i--)
    {
        init = (26*init + str[i]-'a')%mod;
    }
    int res = 0;
    if(check(init, n-1))res++;
    for(int i=n-1-k;i>=0;i--)
    {
        init = (26*(init-(str[i+k]-'a')*h) + str[i]-'a')%mod;
        if(init<0)init = (init+mod)%mod;
        if(check(init, i+k-1))res++;
    }
    printf("%d\n", res);
}
