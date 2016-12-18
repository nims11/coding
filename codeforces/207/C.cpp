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
    int n;
    int a[5] = {0};
    in_I(n);
    for(int i = 0;i<n;i++)
    {
        int x;in_I(x);
        a[x]++;
    }
    int ans = 0;
    int x;

    // 1 -> 2
    x = min(a[1], a[2]);
    ans += x;
    a[1] -= x;
    a[2] -= x;
    a[3] += x;

    // 1 -> 3
    x = min(a[1], a[3]);
    ans += x;
    a[1] -= x;
    a[3] -= x;
    a[4] += x;

    // 2.1 -> 1
    x = a[1]/3;
    ans += 2*x;
    a[1] %= 3;
    a[3] += x;

    // 1 -> 3
    x = min(a[1], a[3]);
    ans += x;
    a[1] -= x;
    a[3] -= x;
    a[4] += x;

    // 1 -> 1
    if(a[1] == 2)
        a[1] = 0, a[2]++, ans++;

//    cout<<a[1]<<" "<<a[2]<<endl;

    // 4 -> 2
    x = min(a[4], a[2]);
    ans += x;
    a[2] -= x;
    a[4] -= x;
    a[3] += x;

    // 2 -> 3
    x = min(2*a[2], (a[3]/2)*2);
    ans += x;
    a[2] -= x;
    a[3] -= 2*x;
    a[4] += 2*x;

    if(a[1] || a[2])
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}
