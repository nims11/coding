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
vector<int> Y, X;
int arr[40];
int n,a,b;
void build_X(int idx, int sum)
{
    if(idx == n/2 )
    {
        X.push_back(sum);
        return;
    }
    build_X(idx+1, sum);
    build_X(idx+1, sum+arr[idx]);
}
void build_Y(int idx, int sum)
{
    if(idx == n )
    {
        Y.push_back(sum);
        return;
    }
    build_Y(idx+1, sum);
    build_Y(idx+1, sum+arr[idx]);
}
int main()
{
    scanf("%d%d%d", &n, &a, &b);

    for(int i=0;i<n;i++)
        in_I(arr[i]);
    build_X(0, 0);
    build_Y(n/2, 0);
    sort(Y.begin(), Y.end());
    long long res = 0;
    for(int i=0;i<X.size();i++)
    {
        res += upper_bound(Y.begin(), Y.end(), b-X[i]) - lower_bound(Y.begin(), Y.end(), a-X[i]);
    }
    printf("%lld\n", res);
}
