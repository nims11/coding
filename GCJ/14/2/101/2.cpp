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
int main()
{
    int N;
    in_I(N);
    int arr[N];
    for(int i = 0;i<N;i++)
        in_I(arr[i]);
    int P, Q;
    in_I(P);
    in_I(Q);
    vector<int> pts;
    pts.push_back(P);
    pts.push_back(Q);
    sort(arr, arr+N);
    for(int i = 0;i<N;i++)
        if(arr[i]>P && arr[i]<Q)
        pts.push_back(arr[i]);
    for(int i = 1;i<N;i++)
    {
        int x = (arr[i]+arr[i-1])/2;
        if(x>P && x<Q)
            pts.push_back(x);
    }
    int res = -1;
    int ans = 0;
    sort(pts.begin(), pts.end());
    for(int i = 0;i<pts.size();i++)
    {
        int mini = 1e9;
        for(int j = 0;j<N;j++)
            mini = min(mini, abs(pts[i]-arr[j]));
        if(res<mini)
            ans = pts[i], res = mini;
    }
    printf("%d\n", ans);
}
