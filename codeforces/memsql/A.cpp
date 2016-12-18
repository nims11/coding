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
int n = 10;
pair<int, int> l[10], r[10];
bool poss(int mask)
{
    int min_x = 10000000, max_x = -1, min_y = 10000000, max_y = -1;
    long long ar2 = 0;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
            min_x = min(l[i].first, min_x),
            min_y = min(l[i].second, min_y),
            max_x = max(r[i].first, max_x),
            max_y = max(r[i].second, max_y),
            ar2 += (r[i].first-l[i].first)*1LL*(r[i].second-l[i].second);
    }
    if(max_x-min_x != max_y-min_y)return false;

    long long ar1 = (max_x-min_x)*1LL*(max_y-min_y);

    return (ar1==ar2);
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
        cin>>l[i].first>>l[i].second>>r[i].first>>r[i].second;
    for(int i=1;i<(1<<n);i++)
    {
        if(poss(i))
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
