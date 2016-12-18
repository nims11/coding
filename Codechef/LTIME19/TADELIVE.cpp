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
int N, X, Y;
int arr1[100001], arr2[100001];
bool cmp(int a, int b){
    return abs(arr1[a]-arr2[a])>abs(arr1[b]-arr2[b]);
}
int main()
{
    in_I(N);
    in_I(X);
    in_I(Y);
    for(int i = 0;i<N;i++){
        in_I(arr1[i]);
    }
    for(int j =0;j<N;j++)
        in_I(arr2[j]);
    int res = 0;
    vector<int> diff;
    for(int i = 0;i<N;i++){
        diff.push_back(i);
    }
    sort(diff.begin(), diff.end(), cmp);
    for(int i = 0;i<N;i++){
        int d = diff[i];
        if(!X)
            res += arr2[d];
        else if(!Y)
            res += arr1[d];
        else if(arr1[d] > arr2[d])
            res += arr1[d], X--;
        else
            res += arr2[d], Y--;
    }
    printf("%d\n", res);
}
