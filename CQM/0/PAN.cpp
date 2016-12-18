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
    in_T
    {
        long long n,x;
        in_L(n);
        x = n;
        int tot = 0;
        while(x)
        {
            tot++;
            x>>=1;
        }
        int ans = 0;
        x = 1LL<<tot;
        int tot_2 = tot;
        while(x)
        {
            if(n&x)
            {

            }else
            {
                ans += tot_2-tot;
                tot_2--;
            }
            tot--;
            x>>=1;
        }
        if(ans%2 == 0)
            printf("PRO\n");
        else
            printf("NOOB\n");
    }
}
