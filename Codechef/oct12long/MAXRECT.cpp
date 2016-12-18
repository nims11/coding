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
pair<long long,int> sum_R[300],sum_C[300];
    int arr[300][300];
int main()
{
    int H,W;
    int max1=-(1<<29),maxr,maxc;
    scanf("%d%d",&H,&W);

    for(int i=0;i<H;i++)
    {
        sum_R[i].first=0;
        sum_R[i].second = i;
        for(int j=0;j<W;j++)
        {
            in_I(arr[i][j]);
            if(arr[i][j]>max1)
                maxr = i, maxc = j, max1 = arr[i][j];
            sum_R[i].first+=arr[i][j];
        }
    }
    for(int j=0;j<W;j++)
    {
        sum_C[j].first = 0;
        sum_C[j].second = j;
        for(int i=0;i<H;i++)
            sum_C[j].first+=arr[i][j];
    }
    sort(sum_R,sum_R+H);
    set<int> R,C;
    for(int i=0;i<H;i++)
    {
        if(sum_R[i].first<0)
        {
            for(int j=0;j<W;j++)
                sum_C[j].first-=arr[sum_R[i].second][j];
            R.insert(sum_R[i].second);
        }
    }
    sort(sum_C,sum_C+W);
    for(int i=0;i<W;i++)
    {
        if(sum_C[i].first<0)
        {
            C.insert(sum_C[i].second);
        }
    }
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
