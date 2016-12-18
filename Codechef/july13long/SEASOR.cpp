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
#include<cassert>
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
int arr[1003];
int n, k;
int tot, max_tot;
vector<int> ans;
bool solved(int st, int end)
{
    for(int i=st;i<=end;i++)
        if(arr[i] != i)
            return false;
    return true;
}
bool sorted(int *a, int *b)
{
    a++;
    while(a <= b)
    {
        if(*(a-1)>*a)
            return false;
        a++;
    }
    return true;
}
void solve(int st)
{
//    cout<<st<<endl;
    int end = min(n-1, st+k-1);
    int curr_end = n-1;
    int curr_st = n-1;
    while(!solved(st, end) && ans.size()<=max_tot)
    {
        while(arr[curr_end]>end)
            curr_end--;
        int tmp = arr[curr_end];
        curr_st = max(st, curr_end-k+1);
        if(!sorted(arr+curr_st, arr+min(n, curr_st+k)))
        {
            sort(arr+curr_st, arr+min(n, curr_st+k));
            ans.push_back(curr_st);
        }
        for(int i=curr_st; arr[i]<=end && i<min(n, curr_st+k);i++)
            curr_end = i;
        if(curr_end-curr_st+1 > 3*k/4)
        {
            while(curr_st != st)
            {
                int a = max(st, curr_st-(curr_end-curr_st+1)/2);
                if(!sorted(arr + a, arr+ min(n, a+k)))
                {
                    sort(arr + a, arr+ min(n, a+k));
                    ans.push_back(a);
                }
                if(!sorted(arr+curr_st, arr+min(n, curr_st+k)))
                {
                    sort(arr+curr_st, arr+min(n, curr_st+k));
                    ans.push_back(curr_st);
                }
                curr_st = a;
                for(int i=curr_st; arr[i]<=end && i<min(n, curr_st+k); i++)
                    curr_end = i;
            }
        }
    }
    if(st+k<n)
        solve(st+k);
}
int main()
{
    in_T
    {
        tot = 0;
        ans.clear();
        in_I(n);
        in_I(k);
        max_tot = n*n/k + 1000;
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        multiset<pair<int, int> > x;
        for(int i=0;i<n;i++)
            x.insert(make_pair(arr[i], i));
        int cnt = 0;
        for(multiset<pair<int, int> >::iterator it = x.begin(); it != x.end(); it++)
        {
            arr[it->second] = cnt++;
        }
//        for(int i=0;i<n;i++)
//            cout<<arr[i]<<" ";
//        newline;
        solve(0);
        if(ans.size()<=max_tot)
        {
            printf("%d\n", ans.size());
            for(int i=0;i<ans.size();i++)
            {
                assert(ans[i]>=0 && ans[i]<n);
                printf("%d ", ans[i]+1);
            }
            if(ans.size())
            newline;
        }else
            printf("0\n");
    }
}
