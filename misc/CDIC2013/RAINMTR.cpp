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
int arr[1000010], n, k;
int main()
{
    in_T
    {
        in_I(n);in_I(k);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        int end = n-1, curr = 0;
        int ans;
        while(1)
        {
            if(arr[end]<arr[curr])
            {
                if(k == 1)
                {
                    ans = arr[end];break;
                }
                end--;
                k--;
            }else
            {
                if(k == 1)
                {
                    ans = arr[curr];break;
                }
                curr++;
                k--;
            }
        }
        printf("%d\n", ans);
    }
}
