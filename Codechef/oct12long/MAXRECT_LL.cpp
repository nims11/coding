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
#include<set>
#include<stack>
#include<utility>
#include<list>
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
long long sum_R[301],sum_C[301];
int arr[300][300];
bool row_sort(int a,int b)
{
    return sum_R[a]<sum_R[b];
}
bool col_sort(int a,int b)
{
    return sum_C[a]<sum_C[b];
}
#define INF 1000000000000000
int main()
{
    int H,W;
    int max1=-(1<<29),maxr,maxc;
    scanf("%d%d",&H,&W);
    sum_R[H] = INF;
    sum_R[W] = INF;
    for(int i=0;i<H;i++)
    {
        sum_R[i]=0;
        for(int j=0;j<W;j++)
        {
            in_I(arr[i][j]);
            if(arr[i][j]>max1)
                maxr = i, maxc = j, max1 = arr[i][j];
            sum_R[i]+=arr[i][j];
        }
    }
    for(int j=0;j<W;j++)
    {
        sum_C[j] = 0;
        for(int i=0;i<H;i++)
            sum_C[j]+=arr[i][j];
    }

    set<int> R,C;

    set<int> rows(row_sort),cols(col_sort);
    for(int i=0;i<=H;i++)
        rows.insert(i);
    for(int j=0;j<=W;j++)
        cols.insert(j)





    if(R.size()==H||C.size()==W)
    {
        printf("1 1\n%d\n%d",maxr,maxc);
        return 0;
    }
    printf("%d %d\n",H-R.size(),W-C.size());
    for(int i=0;i<H;i++)
    {
        if(R.find(i)==R.end())
            printf("%d ",i);
    }
    newline;
    for(int i=0;i<W;i++)
    {
        if(C.find(i)==C.end())
            printf("%d ",i);
    }
    newline;
}
