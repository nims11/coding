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
    int n,k;
    cin>>n>>k;
    int a[k+1];
    for(int i=1;i<=k;i++)
    cin>>a[i];
    int v[n*k+1];
    for(int i=0;i<=n*k;i++)
    v[i] = 0;
    for(int i=1;i<=k;i++)
    v[a[i]] = i;
    int cnt = 1;
    for(int i=1;i<=k;i++)
    {
        cout<<a[i]<<" ";
        for(int j=1;j<n;j++)
        {
            while(v[cnt])
            cnt++;
            v[cnt] = 1;
            cout<<cnt<<" ";
        }
        cout<<endl;
    }
}
