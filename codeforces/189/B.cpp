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
int arr[100000];
int ans = 0;
int n;
const int INF = 1e9;
int cur_ans = 0;
int dfs(int idx, int par)
{
    if(idx == n-1)
        return -1;

    int curr = 1;
    int y = idx + 1;
    while(y != -1 && curr<=par)
    {
        if(arr[y]<arr[idx])
        {
//            cout<<arr[idx]<<" "<<arr[y]<<endl;
            y = dfs(y, curr++);
        }
        else
            return y;
    }
    if(par == INF)
    {
        cur_ans = max(cur_ans, curr-1);
    }
    return y;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
        in_I(arr[i]);
    int y = 0;
    while(y!=-1)
    {
        y = dfs(y, INF);
    }
    cout<<cur_ans<<endl;
}
