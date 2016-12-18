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
#include<cstring>
#include<cstdlib>
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
int n;
pair<int, int> arr[1000];
int status[1000];
// 0 -> free
// 1 -> selected for 1
// 2 -> for 2
int k;
int main()
{
    in_I(n);
    in_I(k);
    for(int i=0;i<n;i++)
    {
        in_I(arr[i].first);
        arr[i].second = i+1;
    }
    sort(arr, arr+n);
    bool flag = false;
    long long curr = 0;
    int cnt = 0;

    for(int i=0;i<n-1;i++)
    {
        if(status[i] == 0)
        {
            status[i] = 1;
            curr += arr[i].first;
            cnt++;
        }
        if(cnt == k)
        {
            cnt--;
            curr -= arr[i-k+1].first;
            status[i-k+1] = 0;
        }
        if(cnt == k-1)
        {
            if(curr>arr[i+1].first)
            {
                status[i+1] = 1;
                int r = i;
                int l = i-k+1;
                while(l>=0 && r>=0)
                {
                    while(status[r] == 0 && r>=0)r--;
                    if(r<0)
                        break;
                    if(curr-arr[r].first+arr[l].first > arr[i+1].first)
                    {
                        status[r] = 0;
                        status[l] = 1;
                        curr = curr-arr[r].first+arr[l].first;
                        l--;
                    }
                    r--;
                }
                cnt++;
                flag = true;
                break;
            }
        }
    }
    if(!flag)
    {
        printf("No\n");
        return 0;
    }
    flag = false;
    vector<int> X;
    vector<int> ans1;
    for(int i=0;i<n;i++)
    {
        if(status[i] == 1)
        {
            ans1.push_back(i);
        }else
        {
            X.push_back(i);
        }
    }
        curr = 0;
    cnt = 0;
    for(int i=0;i<X.size()-1;i++)
    {
        if(status[X[i]] == 0)
        {
            status[X[i]] = 2;
            curr += arr[X[i]].first;
            cnt++;
        }
        if(cnt == k)
        {
            cnt--;
            curr -= arr[X[i-k+1]].first;
            status[X[i-k+1]] = 0;
        }
        if(cnt == k-1)
        {
            if(curr>arr[X[i+1]].first)
            {
                status[X[i+1]] = 2;
                cnt++;
                flag = true;
                break;
            }
        }
    }
    if(!flag)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    for(int i=0;i<ans1.size();i++)
        printf("%d ", arr[ans1[i]].second);
    for(int i=0;i<n;i++)
        if(status[i] == 2)
            printf("%d ", arr[i].second);
    newline;
}
