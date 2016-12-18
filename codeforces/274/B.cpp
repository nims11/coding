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
    int n, l, x, y;
    in_I(n);in_I(l);in_I(x);in_I(y);
    int arr[n];
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    int res = 2;
    int prevX = 0, prevY = 0;
    int forX, forY;
    for(int i = 1;i<n;i++){
        if(binary_search(arr, arr+n, arr[i-1]+x))
            prevX = 1, forX = -1;
        if(binary_search(arr, arr+n, arr[i-1]+y))
            prevY = 1, forY = -1;
    }
    if(prevX && prevY){
        res = 0;
    }
    if(prevX || prevY)
        res = min(res, 1);
    for(int i = 1;i<n;i++){
if(!prevX && arr[i]-x >=0 ){
            int req = arr[i]-x;
            forX = req;
            if(binary_search(arr, arr+n, req+y) || binary_search(arr, arr+n, req-y)){
                if(res > 1){
                    res = 1;
                    forX = req;
                    forY = req;
                    break;
                }
            }
        }
        if(!prevY && arr[i]-y >=0){
            int req = arr[i]-y;
            forY = req;
            if(binary_search(arr, arr+n, req+x) || binary_search(arr, arr+n, req-x)){
                if(res > 1){
                    res = 1;
                    forX = forY = req;
                    break;
                }
            }
    }

        if(!prevX && arr[i-1]+x <= l){
            int req = arr[i-1]+x;
            forX = req;
            if(binary_search(arr, arr+n, req+y) || binary_search(arr, arr+n, req-y)){
                if(res > 1){
                    res = 1;
                    forX = req;
                    forY = req;
                    break;
                }
            }
        }
        if(!prevY && arr[i-1]+y <= l){
            int req = arr[i-1]+y;
            forY = req;
            if(binary_search(arr, arr+n, req+x) || binary_search(arr, arr+n, req-x)){
                if(res > 1){
                    res = 1;
                    forX = forY = req;
                    break;
                }
            }
    }
    }
    printf("%d\n", res);
    if(res == 1){
        if(forX != -1)
            printf("%d\n", forX);
        else if(forY != -1)
            printf("%d\n",forY);
    }else if(res == 2){
        printf("%d %d\n", forX, forY);
    }
}
