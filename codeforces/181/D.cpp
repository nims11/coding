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
long long mod = 7340033;
long long getans(int n, int k)
{
    if(k == 0)
        return 1;
    if(n%2 ==0 || k<0)
        return 0;

    long long ret = 0;
    ret = (ret+4*getans(n/2, k-1))%mod;
    ret = (ret+getans(n/2, 2)+6*4)%mod;
    ret = (ret+4*4 + 16*
}
int main()
{
    in_T
    {
        int n,k;
        in_I(n);
        in_I(k);
        cout<<getans(n)<<endl;
    }
}
