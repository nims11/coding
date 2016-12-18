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
        int n,m,k,l;
        scanf("%d%d%d%d", &n, &m, &k, &l);
        int left_win = 2*max(1,m-k+1),
            right_win = 2*min(m, n-k+1),
            left_lost = 2*max(1, l-k+1),
            right_lost = 2*min(l, n-k+1);
        left_win +=k-m-1;
        right_win +=k-m-1;
        left_lost += k-l-1;
        right_lost += k-l-1;
        if(l>=left_win && l<=right_win)
            if((left_win&1) == (l&1))
                {printf("ACM\n");continue;}

        if(left_lost<=left_win && right_lost>=right_win)
            if((left_win&1) == (left_lost&1))
                {
                    printf("NONACM\n");
                    continue;
                }
        printf("DRAW\n");
    }
}
