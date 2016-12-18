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
    in_T
    {
        int l,n,r, X, R, C;
        in_I(l);in_I(r);in_I(n);
        int tot = l+r;
        while(n--)
        {
            in_I(X);
            R = 1 + ((X-1)/tot);
            C = 1 + ((X-1)%tot);
            if(R%2 == 0)
            {
                C = 1+tot-C;
            }
            if(C<=l)
                printf("L %d %d\n", R, C);
            else
                printf("R %d %d\n", R, C);
        }
    }
}
