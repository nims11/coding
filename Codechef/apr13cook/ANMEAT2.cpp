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
        int n,k;
        in_I(n);
        in_I(k);
        if(k == 1)
        {
            cout<<1<<endl;
        }else
        if(2*k<=n)
        {
            for(int i=1;i<=k;i++)
                cout<<(i*2)<<" ";
            cout<<endl;
        }else
        cout<<-1<<endl;
    }
}
