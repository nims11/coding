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
const int INF = 1e9;
using namespace std;
int N,B,H,W;
int main()
{
    while(~scanf("%d%d%d%d", &N, &B, &H, &W))
    {
        int mini = INF;
        for(int i=0;i<H;i++)
        {
            int P;
            in_I(P);
            int price = P*N;
            bool flag = false;
            for(int j=0;j<W;j++)
            {
                int x;
                in_I(x);
                flag |= (x>=N);
            }
            if(flag && mini>price && price<=B)
                mini = price;
        }
        if(mini == INF)
        {
            printf("stay home\n");
        }else
            printf("%d\n", mini);
    }
}
