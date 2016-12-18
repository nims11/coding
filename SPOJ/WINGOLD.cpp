/*
    Nimesh Ghelani (nims11)
    Tabulate the probablities and calculate the total probablity of the favourable event.
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
    in_T
    {
        double p;int n,m;
        in_F(p);in_I(n);in_I(m);
        double tmp = 1-p;
        double foo = p;
        double res = 0;
        for(int i=0;i<m;i++)
        {
            tmp*=p;
            res += tmp*pow(1-foo, n-1);
            foo*=p;
        }
        res *= n;
        printf("%.4lf\n", res);
    }
}
