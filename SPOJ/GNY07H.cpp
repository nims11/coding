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
#include<utility>
#include<climits>
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
    int ans[22];
    ans[0] = ans[1] = 1;
    int n_1=1,n_2=1;
    int sum=1,sum_even=1,sum_odd = 1;
    for(int i=2;i<22;i++)
    {
        ans[i] = n_2 + n_1 + (i%2?sum_odd:sum_even) + 2*(sum);
        sum += n_1;
        if(i%2)sum_odd += ans[i];
        else sum_even += ans[i];
        n_2 = n_1;
        n_1 = ans[i];
//        cout<<i<<" "<<ans[i]<<endl;
    }
    int c = 1;
    in_T
    {
        int n;
        in_I(n);
        printf("%d %d\n",c,ans[n]);
        c++;
    }
}
