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
long long K;
int arr[100010];
int main()
{
    in_I(n);
    in_L(K);
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    int maxi = arr[0];
    for(int i  =1;i<n;i++)
        maxi = max(arr[i], maxi);
    for(int i = 0;i<n;i++)
        arr[i] = -arr[i]+maxi;

    long long tot = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i-1] < arr[i])
            tot += arr[i]-arr[i-1];
    }
    if(tot>K)
        cout<<0<<endl;
    else
        cout<<(K-tot+1)<<endl;
}
