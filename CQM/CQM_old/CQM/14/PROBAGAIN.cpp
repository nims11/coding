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
// w b 0->p 1->d
double dp[1001][1001][2];
int main()
{
    for(int i=0;i<=1000;i++)
        dp[0][i][1] = 1, dp[0][i][0] = 0.0f;
    for(int i=1;i<=1000;i++)
        dp[i][0][0] = dp[i][0][1] = 1;

    for(int w=1;w<=1000;w++)
    {
        for(int b=1;b<=1000;b++)
        {
            dp[w][b][0] = double(w)/(w+b) + (double(b)/(w+b))*(1-dp[w][b-1][1]);
            dp[w][b][1] = double(w)/(w+b) + (double(b)/(w+b))*(double(b-1)/(w+b-1))*(b-2>=0?(1-dp[w][b-2][0]):0)
                            + (double(b)/(w+b))*(double(w)/(w+b-1))*(1-dp[w-1][b-1][0]);
        }
    }
    in_T
    {
        int w,b;
        in_I(w);
        in_I(b);
        printf("%.9lf\n", dp[w][b][0]);
    }
}
