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
int arr[100011];
int main()
{
    while(in_I(n) != EOF){
        for(int i = 0;i<n;i++)
            in_I(arr[i]);

        long long res = 0;
        long long prev = 0;
        for(int i = 1;i<n;i++){
            if(arr[i]<arr[i-1]){
                int cur = arr[i-1]-arr[i];
                res += max((long long)0, (cur-prev));

                prev = cur;
                arr[i] = arr[i-1];
            }else
                prev = 0;
        }
        printf("%lld\n", res);
    }
}
