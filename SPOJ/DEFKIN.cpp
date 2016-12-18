/*
    Nimesh Ghelani (nims11)
    Find the largest row and col separation
    ans = their product
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
        int w,h, n, r, c;
        scanf("%d%d%d", &w, &h, &n);
        int row[w+1], col[h+1];
        for(int i=0;i<=w;i++)
            row[i] = 0;
        for(int j=0;j<=h;j++)
            col[j] = 0;
        row[w] = 1;
        col[h] = 1;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d", &r,&c);
            row[r-1] = 1;
            col[c-1] = 1;
        }
        int pre = -1;
        int curr_max = 0;
        for(int i=0;i<=w;i++)
        {
            if(row[i])
            {
                curr_max = max(curr_max, i-pre-1);
                pre = i;
            }
        }
        int pre2 = -1;
        int curr_max2 = 0;
        for(int i=0;i<=h;i++)
        {
            if(col[i])
            {
                curr_max2 = max(curr_max2, i-pre2-1);
                pre2 = i;
            }
        }
        printf("%d\n", curr_max*curr_max2);
    }
}
