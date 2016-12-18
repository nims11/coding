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
int main()
{
    int n;
    cout<<acos(-1)<<endl;
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        int x, y;
        in_I(x);
        in_I(y);
        double mini = 100000000;
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            int xx, yy, rr;
            in_I(xx);in_I(yy);in_I(rr);
            double foo = abs(sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y))-rr);
            if(foo<mini)
                mini = foo, ans = i+1;
        }
        printf("%d\n", ans);
    }
}
