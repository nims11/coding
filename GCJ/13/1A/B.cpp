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
int v[100];
int ans = 0;
int e,r,n;
void getans(int idx, int curr, int gain)
{
    if(idx == n)
    {
        ans = max(ans, gain);
        return;
    }
    for(int i=0;i<=curr;i++)
    {
        getans(idx+1, min(e,r+curr-i), gain+i*v[idx]);
    }
}
int main()
{
    int c = 0;
    in_T
    {
        c++;
        cin>>e>>r>>n;
        for(int i=0;i<n;i++)
            cin>>v[i];
        ans = 0;
        getans(0, e, 0);
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
}
