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
int search_b(vector<int> &nums, int n)
{
    int start=0,end=nums.size()-1;
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(nums[mid]<n)
        {
            start=mid+1;
            continue;
        }
        if(nums[mid]>=n)
        {
            end=mid;
            continue;
        }
    }
    return end;
}

int main()
{
    in_T
    {
        int n,l,h;
        scanf("%d%d%d",&n,&l,&h);
        vector<int> n_2;
        int nums[n];
        for(int i=0;i<n;i++)
        {
            in_I(nums[i]);
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                n_2.push_back(nums[i]+nums[j]);
        sort(n_2.begin(), n_2.end());
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int foo = search_b(n_2, nums[i]);
            if(foo!=-1 && n2[foo]<=h)
            ans++;
        }
        printf("%d\n", ans);
    }
}
