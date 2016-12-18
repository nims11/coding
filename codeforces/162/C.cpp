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
    int n,q;
    cin>>n>>q;
    int v[n], c[n];
    for(int i=0;i<n;i++)
        in_I(v[i]);
    int cls = 0;
    for(int i=0;i<n;i++)
    {
        in_I(c[i]);
    }
    long long c_max[n][2];
    long long a_max[2][2];
    while(q--)
    {
        int a,b;

        for(int i=0;i<n;i++)
            c_max[i][0] = -1;
        a_max[0][0] = -1;
        a_max[1][0] = -1;
        for(int i=0;i<n;i++)
        {
            long long foo = -1, bar;
            if(c_max[c[i]][0] != -1)
            {
                bar = c_max[c[i]][]
            }
        }
    }
}
