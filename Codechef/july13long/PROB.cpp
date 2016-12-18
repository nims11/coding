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
long long T1, T2, T3, T4, foo;
double c1, c2;
int main()
{
    in_T
    {
        scanf("%lld%lld%lld%lld", &T1, &T2, &T3, &T4);
        foo = T1 + T2 + T3 - T4;
        c1 = T1 * foo;
        c2 = T2 * foo;
        printf("%.6lf\n", c1/(c1+c2));
    }
}
