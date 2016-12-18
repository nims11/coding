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
int maxi[11];
int main()
{
    int c = 0;
    int pow_2[60];
    pow_2[0] = 1;
    for(int i=1;i<60;i++)
        pow_2[i] = pow_2[i-1]*2;
    in_T
    {
        c++;
        cout<<"Case #"<<c<<": ";
        int n;
        long long p;
        cin>>n>>p;
        int x = n-1;
        p--;
        for(;p&(1LL<<x);x--);
//        cout<<x<<endl;
        x = n-x-1;
        cout<<pow_2[x+1]-2<<" ";
//        cout<<x<<endl;

        cout<<pow_2[n]-1-pow_2[x]+2<<endl;
    }
}
