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
long long arr[1000000], pre[1000000], post[1000000];
long long sum;
int main()
{
    in_I(n);
    for(int i = 1;i<=n;i++)
        in_I(arr[i]);
    for(int i = 1;i<=n;i++){
        pre[i] = pre[i-1]+arr[i];
        post[n-i+1] = post[n-i+2] + arr[n-i+1];
        sum += arr[i];
    }
    long long res = 0;
    long long avg = sum/n;
    for(int i = 1;i<=n;i++){
        long long leftReq = (i-1)*avg,
             rightReq = (n-i)*avg;
        long long left = pre[i-1],
             right = post[i+1];
        if(left<leftReq)
            res += leftReq - left;
        if(right < rightReq)
            res += rightReq - right;
    }
    cout<<res<<endl;
}
