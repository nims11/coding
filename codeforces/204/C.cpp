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
    in_I(n);
    int cnt_a = 0, cnt_b = 0;
    int x, y;
    int sum_1 = 0, sum_2 = 0, sum_3 = 0;
    for(int i = 0; i<(n<<1); i++)
    {
        scanf("%d.%d", &x, &y);
        x = x*1000 + y;
        sum_1 += x;
        if(x%1000 == 0)
        {
            cnt_a++;
            sum_2 += x;
        }else
        {
            cnt_b++;
            sum_2 += (x/1000)*1000;
        }
    }
//    cout<<sum_1<<" "<<sum_2<<endl;
//    cout<<cnt_a<<" "<<cnt_b<<endl;
    int ans = 1000000000;
    int lt = min(n, cnt_b);
    for(int i = max(0, cnt_b-n); i<=lt; i++)
    {
        ans = min(ans, abs(sum_1-(sum_2+i*1000)));
    }
    printf("%d.%.3d\n", ans/1000, ans%1000);
}
