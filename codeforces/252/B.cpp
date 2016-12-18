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
    int n,v,a,b;
    cin>>n>>v;
    int foo[4000] = {0}, bar[4000] = {0};
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        foo[a] += b;
    }
    int res = 0;
    for(int i = 0;i<4000;i++)
    {
        int cur = min(v, bar[i]);
        int left = v-cur;
        res += cur;
        cur = min(left, foo[i]);
        res += cur;
        left = left-cur;
        bar[i+1] += foo[i]-cur;
    }
    cout<<res<<endl;
}
