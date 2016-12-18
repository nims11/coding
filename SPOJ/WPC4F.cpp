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
        int n;
        in_I(n);
        int a,d,b;
        int dp_a = 0, dp_d = 0, dp_b = 0, dp_a_tmp, dp_d_tmp, dp_b_tmp;
        for(int i=0;i<n;i++)
        {
            cin>>a>>d>>b;
            dp_a_tmp = a+min(dp_d,dp_b);
            dp_d_tmp = d+min(dp_a,dp_b);
            dp_b_tmp = b+min(dp_a,dp_d);
            dp_a = dp_a_tmp;
            dp_d = dp_d_tmp;
            dp_b = dp_b_tmp;
        }
        cout<<min(dp_a, min(dp_b, dp_d))<<endl;;
    }
}
