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
int n,k;
const int bar=50;
double foo[100001][bar];
int main()
{
    for(int i=0;i<bar;i++)
        foo[0][i] = 0;
    for(int i=1;i<100001;i++)
        foo[i][0] = i;
    for(int k=1;k<bar;k++)
    {
        double tmp = foo[0][k-1];
        for(int n=1;n<100001;n++)
        {
            foo[n][k] = tmp/n;
            tmp += foo[n][k-1];
        }
    }
    in_T
    {
        int n,k;
        in_I(n);in_I(k);
        double ans=0;
        if(k<bar)
        {
            ans = foo[n][k];
        }
        printf("%.7lf\n", ans);
    }
}
