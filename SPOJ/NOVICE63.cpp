/*
    Nimesh Ghelani (nims11)
    Set the most significant bit and find the number of combinations
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
#define VVVV 62
long long pow_2[VVVV];
long long C[61][61] = {{0}};
long long foo[61];
int main()
{
    pow_2[0] = 1;
    for(int i=1;i<VVVV;i++)
        pow_2[i] = pow_2[i-1]<<1;
    for(int i=0;i<61;i++)
        C[i][0] = 1;

    for(int i=1;i<61;i++)
    {
        for(int j=1;j<=i;j++)
            C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
    foo[0] = 0;
    for(int i=1;i<61;i++)
    {
        if(i%2 == 0)
            foo[i] = 0;
        else
            foo[i] = C[i][(i/2 + 1)];

        foo[i] += foo[i-1];
    }
    long long n;
    in_T
    {
        in_L(n);
        printf("%lld\n", foo[(n==2?0:-1) + int(lower_bound(pow_2, pow_2+VVVV, n) - pow_2)]);
    }
}

