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
int n,len;
unsigned long long h1, h2;
char str[2000001];
int d = 26;
unsigned long long POW(unsigned long long r, unsigned int n)
{
    unsigned long long ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = ans*r;
        n >>= 1;
        r = r*r;
    }
    return ans;
}
int main()
{
    in_I(n);
    unsigned long long Hs[n];
    unsigned long long Hs_rev[n];
    int lens[n];
    for(int i=0;i<n;i++)
    {
        in_I(len);
        in_S(str);
        lens[i] = len;
        h1 = h2 = 0;
        for(int j=0;j<len;j++)
            h1 = h1*d + str[j]-'a',
            h2 = h2*d + str[len-j-1]-'a';
        Hs[i] = h1;
        Hs_rev[i] = h2;
    }
    long long res = 0;
    for(int i=0;i<n;i++)
        lens[i] = POW(d, lens[i]);
    for(int i=0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            h1 = Hs[i]*lens[j] + Hs[j];
            h2 = Hs_rev[j]*lens[i] + Hs_rev[i];
            if(h1 == h2)
                res++;
        }
    }
    res = (res<<1) + n;
    printf("%lld\n", res);
}


