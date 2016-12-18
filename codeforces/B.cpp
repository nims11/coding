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
int arr[1000000];
int getL(int val, int n){
    int st = 0, end = n-1;
    while(st < end){
        int mid = (st+end+1)/2;
        if(arr[mid]>=val)
            end = mid-1;
        else
            st = mid;
    }
    return st;
}
int main()
{
    int n;
    in_I(n);
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    pair<int, int> res = make_pair(arr[0], arr[0]);
    sort(arr, arr+n);
    for(int i = 0;i<n;i++){
        int cur = 2;
        while(arr[i]*(cur-1) <= arr[n-1]){
            int pos = getL(arr[i]*cur, n);
            if(arr[pos]%arr[i] > res.first%res.second)
                res = make_pair(arr[pos], arr[i]);
            cur++;
        }
    }
    printf("%d\n", res.first%res.second);
}
