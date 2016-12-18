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
double foo[2000];
int n,tmp,i,j;
int pre[2001];
int main()
{
    pre[0] = 0;
    in_T
    {
        in_I(n);
        for(i=0;i<n;i++)
        {
            in_F(foo[i]);
            pre[i+1] = pre[i]+foo[i];
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                foo[j] = pre[j+i+1]-pre[j]-(foo[j]+foo[j+1])/2;
            }
        }
        printf("%.3lf\n",foo[0]);
    }
}
