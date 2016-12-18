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
int main()
{
    in_T
    {
        int n,m,k;
        in_I(n);in_I(m);in_I(k);
        if(n == 1 && m == 1)
        {
            printf("0\n");
        }else if((n == 1 && m == 2) || (m == 1 && n == 2))
            printf("0\n");
        else if(n == 1 || m == 1)
        {
            printf("%d\n", k);
        }else
            printf("%d\n", (k+1)>>1);
    }
}
