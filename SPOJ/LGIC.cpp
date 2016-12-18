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
int main()
{
    long long unsigned fact[21], res[21];
    fact[0] = 1;
    for(int i=1;i<21;i++)
        fact[i] = fact[i-1]*i;
    res[1] = 1;
    for(int i=2;i<21;i++)
    {
        res[i] = res[i-1]*2+i-2;
    }
    long long n;

    in_L(n);
    cout<<fact[n]+res[n]<<endl;
}
