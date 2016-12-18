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
int n;
int arr[100001];
bool check(long long X){
    long long prev = -1000000000000LL;
    for(int i = 0;i<n;i++){
        if(prev>=arr[i]){
            if(arr[i]+X>prev){
                prev = prev+1;
            }else return false;
        }else{
            prev = max(prev+1, arr[i]-X);
        }
    }
    return true;
}
int main()
{
    while(in_I(n) != EOF){
        long long st = 0, end = 10000000000000LL;
        for(int i = 0;i<n;i++)
        {
            in_I(arr[i]);
        }
        while(st<end){
            long long mid = (st+end)/2;
            if(check(mid)){
                end = mid;
            }else{
                st = mid+1;
            }
        }
        printf("%lld\n", end);
    }
}
