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
    int n,m;
    cin>>n>>m;
    int x;
    int max_n, min_n, max_m, min_m;
    cin>>max_n;
    min_n = max_n;
    for(int i = 1; i<n;i++)
    {
        in_I(x);
        min_n = min(min_n, x);
        max_n = max(max_n, x);
    }
    cin>>max_m;
    min_m = max_m;
    for(int i = 1; i<m;i++)
    {
        in_I(x);
        min_m = min(min_m, x);
        max_m = max(max_m, x);
    }
    if(max_n >= min_m)
    {
        cout<<-1<<endl;
    }else
    {
        int res = max(2*min_n, max_n);
        if(res >= min_m)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
}
