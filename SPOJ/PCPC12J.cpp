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
int main()
{
    in_T
    {
        int xyz[101] = {0};
        int n,x;
        in_I(n);
        for(int i=0;i<n;i++)
        {
            in_I(x);
            xyz[x]++;
        }
        pair<int, int> maxx = make_pair(-1, 10000000);
        for(int i=1;i<=100;i++)
        {
            if(xyz[i] && xyz[i]%i == 0)
                maxx = max(maxx, make_pair(xyz[i], -i));
        }
        printf("%d\n", maxx.second==10000000?-1:-maxx.second);
    }
}
