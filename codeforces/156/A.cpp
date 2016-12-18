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
    int n, tmp;
    in_I(n);
    int a[3] = {0};
    for(int i=0;i<n;i++)
    {
        in_I(tmp);
        a[i%3]+=tmp;
    }
    int q = max(a[0], max(a[1], a[2]));
    if(q == a[0])
        cout<<"chest\n";
    else if(q==a[1])
        cout<<"biceps\n";
    else
        cout<<"back\n";
}
