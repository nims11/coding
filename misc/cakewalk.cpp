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
    in_T{
        int n, sum = 0;
        in_I(n);
        int arr[n];
        for(int i = 0;i<n;i++)
        {
            in_I(arr[i]);
            sum += arr[i];
        }
        sort(arr, arr+n);
        int cur = 0, idx = n-1;
        while(cur<=sum-cur){
            cur += arr[idx--];
        }
        printf("%d\n", n-idx-1);
    }
}
