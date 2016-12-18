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
int main()
{
    int c = 0;
    in_T
    {
        c++;
        int n,m,k;
        in_I(n);in_I(m);in_I(k);
        int foo = (n==1)+(m==1)+(k==1);
        printf("Case #%d: %lld %d\n", c, (n)*(long long)(m)*(k)-1, (n!=1)*(int)log2(n-1)+(m!=1)*(int)log2(m-1)+(k!=1)*(int)log2(k-1) + 3 - foo);
    }
}
