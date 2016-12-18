/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
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
#define BE(a) a.begin(), a.end()

using namespace std;
int arr[100010];
int N, C;
int foo(int x){
    int cur = x;
    int cnt = C;
    int idx = 1;
    while(cnt && idx<N){
        while(cur < x && idx < N){
            cur += arr[idx] - arr[idx-1];
            idx++;
        }
        if(cur >=x){
            cur = 0;
            cnt--;
        }
    }
    return (cnt == 0);
}
int main()
{
    in_I(N);
    in_I(C);
    for(int i = 0;i<N;i++)
        in_I(arr[i]);
    int st = 1, end = 1000000000;
    sort(arr, arr+N);
    while(st<end){
        int mid = (st + end + 1)/2;
        if(foo(mid)){
            st = mid;
        }else
            end = mid-1;
    }
    printf("%d\n", st);
}
