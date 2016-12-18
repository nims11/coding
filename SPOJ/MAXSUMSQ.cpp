/*
    Nimesh Ghelani (nims11)
    find the max subsum
    find the prefix sum and maintain the count of minimum prefix sum yet encountered.
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
int arr[100000];
multiset<int> foo;
int main()
{
    in_T
    {
        foo.clear();
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        int maxi = arr[0];
        int sum = arr[0];
        if(sum<0)
            sum = -1000000000;
        for(int i=1;i<n;i++)
        {
            if(sum<0)
            {
                sum = 0;
            }
            sum += arr[i];
            maxi = max(sum, maxi);
        }
        for(int i=1;i<n;i++)
            arr[i]+=arr[i-1];
        int mini = 0;
        long long ans = 0, cnt = 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]-mini == maxi)
                ans += cnt;
            if(arr[i] == mini)cnt++;
            else if(arr[i]<mini)
                mini = arr[i], cnt = 1;
        }
        printf("%d %lld\n", maxi, ans);
    }
}
