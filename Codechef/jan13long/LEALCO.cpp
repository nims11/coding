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
int n,k,m;
int arr[17];
bool check(int mask)
{
    bool ret = true;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
        {
            arr[i]++;
        }
    }
    for(int i=0;i<=n-k;i++)
    {
        int max_no = 0, max_freq = 0;
        for(int j=i;j<i+k;j++)
        {
            if(arr[j]>max_no)
            {
                max_no = arr[j];
                max_freq = 0;
            }
            max_freq += (arr[j]==max_no);
        }
        if(max_freq>=m)
        {
            ret = false;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
        {
            arr[i]--;
        }
    }
    return ret;
}
int main()
{
    in_T
    {

        scanf("%d%d%d", &n, &k, &m);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        int lt = 1<<n;
        int ans = 20;
        for(int i=0;i<lt;i++)
        {
            int j = i;
            if(check(j))
            {
                int foo = 0;
                while(j)
                {
                    foo += j&1;
                    j>>=1;
                }
                ans = min(ans, foo);
            }
        }
        if(ans==20)ans = -1;
        printf("%d\n", ans);
    }
}
