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

using namespace std;
int mod = 1000000007;
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
int main()
{
    int n,k;
    in_I(n);
    in_I(k);
    long long foo = POW(n, n-2);
    long long init_tree, add_tree;
    switch(k)
    {
    case 1:
        printf("%d\n", foo);
        break;
    case 2:
        init_tree = (1LL*foo*POW(2, n-2))%mod;
        add_tree = (init_tree*POW((n<<1) - 2, n))%mod;
        printf("%lld\n", add_tree);
    break;
    case 3:
        init_tree = (1LL*foo*POW(3, n-2))%mod;
        add_tree = (init_tree*POW(n*3 - 3, n<<1))%mod;
        printf("%d\n", add_tree);
    break;
    }
}
