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
    int n;
    in_I(n);
    pair<int, int> arr[n];
    for(int i = 0;i<n;i++){
        in_I(arr[i].first);
        in_I(arr[i].second);
    }
    sort(arr, arr+n);
    int cur = min(arr[0].first, arr[0].second);
    for(int i = 1;i<n;i++){
        int mini = min(arr[i].first, arr[i].second);
        int maxi = max(arr[i].first, arr[i].second);
        if(cur <= mini)
            cur = mini;
        else
            cur = maxi;
    }
    printf("%d\n", cur);
}
