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
    int n;
    cin>>n;
    int l[n],r[n];
    int l_1 = 0, r_1=0, r_0=0, l_0=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        if(l[i]==0)l_0++;
        else l_1++;
        if(r[i]==0)r_0++;
        else r_1++;
    }
    cout<<min(l_1,l_0)+min(r_1,r_0)<<endl;

}
