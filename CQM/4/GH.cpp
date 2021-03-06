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
    while(in_I(n) != EOF)
    {
        int x = floor(sqrt(n));
        while(x*x<n)
            x++;
//        x--;
//        cout<<x<<endl;
        int r, c;
        if(x%2)
        {
            r = 1+n-((x-1)*(x-1)+1), c = x;
            if(r > x)
                c -= (r-x), r = x;
        }else
        {
            r = x, c = 1+n-((x-1)*(x-1)+1);
            if(c > x)
                r -= (c-x), c = x;
        }
        printf("(%d,%d)\n", r, c);
    }
}
