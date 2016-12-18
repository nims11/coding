/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
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
#define sqr 1.7320508075688772935274463415059
int main()
{
    in_T
    {
        double a,b,c;
        in_F(a);in_F(b);in_F(c);
        double s = (a+b+c)/2;
        printf("%.2lf\n",0.5*((a*a*sqr/4) + (b*b*sqr/4) + (c*c*sqr/4) + (3*sqrt(s*(s-a)*(s-b)*(s-c)))));
    }
}
